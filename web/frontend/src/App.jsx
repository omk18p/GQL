import { useState } from 'react';
import Editor from '@monaco-editor/react';
import axios from 'axios';
import { Play, Eraser, AlertCircle, CheckCircle } from 'lucide-react';
import './App.css';

function App() {
  const [query, setQuery] = useState('MATCH (n)\nRETURN n');
  const [output, setOutput] = useState('');
  const [errorDetails, setErrorDetails] = useState('');
  const [isLoading, setIsLoading] = useState(false);
  const [status, setStatus] = useState('idle'); // idle, success, error

  const handleRunQuery = async () => {
    setIsLoading(true);
    setStatus('idle');
    setOutput('');
    setErrorDetails('');

    try {
      const response = await axios.post('http://localhost:3001/api/execute', { query });
      
      const { stdout, stderr, exitCode } = response.data;
      
      if (exitCode === 0) {
        setStatus('success');
        setOutput(stdout || 'Query executed successfully with no output.');
        if (stderr) setOutput(prev => prev + '\n[Warnings]:\n' + stderr);
      } else {
        setStatus('error');
        setOutput(stdout || '');
        setErrorDetails(stderr || `Process exited with code ${exitCode}`);
      }
    } catch (err) {
      setStatus('error');
      setErrorDetails(err.message || 'Failed to connect to the backend server.');
    } finally {
      setIsLoading(false);
    }
  };

  const handleClear = () => {
    setQuery('');
    setOutput('');
    setErrorDetails('');
    setStatus('idle');
  };

  return (
    <div className="app-container">
      <header className="header">
        <div className="logo-container">
          <div className="logo-icon">Q</div>
          <h1>GQL Query Engine</h1>
        </div>
        <div className="status-badge">
          {status === 'success' && <><CheckCircle size={16} className="text-green" /> Success</>}
          {status === 'error' && <><AlertCircle size={16} className="text-red" /> Execution Failed</>}
          {status === 'idle' && 'Ready'}
        </div>
      </header>

      <main className="main-content">
        <div className="editor-pane">
          <div className="pane-header">
            <h2>Query Editor</h2>
            <div className="actions">
              <button 
                className="btn btn-secondary" 
                onClick={handleClear}
                disabled={isLoading}
              >
                <Eraser size={16} /> Clear
              </button>
              <button 
                className="btn btn-primary" 
                onClick={handleRunQuery}
                disabled={isLoading || !query.trim()}
              >
                {isLoading ? (
                  <span className="spinner"></span>
                ) : (
                  <><Play size={16} /> Run Query</>
                )}
              </button>
            </div>
          </div>
          <div className="editor-wrapper">
            <Editor
              height="100%"
              defaultLanguage="sql"
              theme="vs-dark"
              value={query}
              onChange={(val) => setQuery(val || '')}
              options={{
                minimap: { enabled: false },
                fontSize: 14,
                lineNumbers: 'on',
                scrollBeyondLastLine: false,
                wordWrap: 'on',
                fontFamily: "'JetBrains Mono', 'Fira Code', Consolas, monospace",
              }}
            />
          </div>
        </div>

        <div className="results-pane">
          <div className="pane-header">
            <h2>Execution Results</h2>
          </div>
          <div className="results-wrapper">
            {status === 'idle' && !output && (
              <div className="empty-state">
                <Play size={48} className="empty-icon" />
                <p>Enter a GQL query and click run to see results here.</p>
              </div>
            )}
            
            {(output || errorDetails) && (
              <div className="terminal-output">
                {output && (
                  <pre className="stdout">{output}</pre>
                )}
                {errorDetails && (
                  <div className="error-box">
                    <div className="error-header">
                      <AlertCircle size={16} />
                      <span>Error Output</span>
                    </div>
                    <pre className="stderr">{errorDetails}</pre>
                  </div>
                )}
              </div>
            )}
          </div>
        </div>
      </main>
    </div>
  );
}

export default App;
