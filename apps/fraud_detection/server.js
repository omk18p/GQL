const express = require('express');
const cors = require('cors');
const bodyParser = require('body-parser');
const { exec } = require('child_process');
const fs = require('fs');
const path = require('path');

const app = express();
const PORT = process.env.PORT || 3002;

app.use(cors());
app.use(bodyParser.json());
app.use(express.static('public'));

// Path to the compiled GQL binary
const GQL_BINARY_PATH = path.resolve(__dirname, '../../gqlparser');

app.get('/api/dataset', (req, res) => {
    // We can just read the graph_data.json directly for visualization
    const dataPath = path.join(__dirname, 'graph_data.json');
    fs.readFile(dataPath, 'utf8', (err, data) => {
        if (err) {
            console.error('Error reading graph data:', err);
            return res.status(500).json({ error: 'Failed to load dataset' });
        }
        try {
            res.json(JSON.parse(data));
        } catch (e) {
            res.status(500).json({ error: 'Invalid JSON' });
        }
    });
});

app.post('/api/execute', (req, res) => {
    const { query } = req.body;

    if (!query) {
        return res.status(400).json({ error: 'Query is required' });
    }

    // Create a temporary file for the query
    const tempFilePath = path.join(__dirname, `temp_query_${Date.now()}.gql`);

    fs.writeFile(tempFilePath, query, (err) => {
        if (err) {
            console.error('Error writing temp file:', err);
            return res.status(500).json({ error: 'Internal server error while writing query file' });
        }

        // Execute the GQL binary with the temp file
        // It will run in the current directory, picking up our custom graph_data.json
        const command = `"${GQL_BINARY_PATH}" "${tempFilePath}"`;
        
        exec(command, { cwd: __dirname }, (error, stdout, stderr) => {
            // Clean up the temp file
            fs.unlink(tempFilePath, (unlinkErr) => {
                if (unlinkErr) console.error('Error deleting temp file:', unlinkErr);
            });

            // GQL C++ outputs everything to stdout (or stderr if failure)
            res.json({
                stdout: stdout || '',
                stderr: stderr || '',
                exitCode: error ? error.code : 0
            });
        });
    });
});

app.listen(PORT, () => {
    console.log(`Fraud Detection Backend Server running on http://localhost:${PORT}`);
});
