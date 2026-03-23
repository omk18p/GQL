const express = require('express');
const cors = require('cors');
const bodyParser = require('body-parser');
const { exec } = require('child_process');
const fs = require('fs');
const path = require('path');

const app = express();
const PORT = process.env.PORT || 3001;

app.use(cors());
app.use(bodyParser.json());

// Path to the GQL binary
const GQL_BINARY_PATH = path.resolve(__dirname, '../../gqlparser');

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
        const command = `"${GQL_BINARY_PATH}" "${tempFilePath}"`;
        
        exec(command, (error, stdout, stderr) => {
            // Clean up the temp file
            fs.unlink(tempFilePath, (unlinkErr) => {
                if (unlinkErr) console.error('Error deleting temp file:', unlinkErr);
            });

            // Even if there's an error code (like syntax error), we want to return the output
            // because the C++ engine writes syntax errors to stderr and exits with 1
            res.json({
                stdout: stdout || '',
                stderr: stderr || '',
                exitCode: error ? error.code : 0
            });
        });
    });
});

app.listen(PORT, () => {
    console.log(`GQL Backend Server running on http://localhost:${PORT}`);
});
