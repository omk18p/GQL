import { useState, useEffect, useRef } from 'react';
import Editor from '@monaco-editor/react';
import axios from 'axios';
import { Play, Eraser, AlertCircle, CheckCircle, Database, Clock, Terminal, Braces, Share2 } from 'lucide-react';
import ForceGraph2D from 'react-force-graph-2d';
import './App.css';

function App() {
  const [query, setQuery] = useState('MATCH (n)\nRETURN n');
  const [output, setOutput] = useState('');
  const [errorDetails, setErrorDetails] = useState('');
  const [isLoading, setIsLoading] = useState(false);
  const [status, setStatus] = useState('idle'); // idle, success, error
  const [executionTime, setExecutionTime] = useState(0);
  const [activeTab, setActiveTab] = useState('graph'); // default to 'graph' array tab
  const [parsedData, setParsedData] = useState(null);
  const graphContainerRef = useRef(null);
  const [graphDim, setGraphDim] = useState({ width: 600, height: 400 });
  const [globalGraphData, setGlobalGraphData] = useState(null);

  useEffect(() => {
    if (activeTab === 'graph') {
      setGlobalGraphData(null); // clear to show loader, then re-fetch
      axios.get('http://localhost:3001/api/dataset')
        .then(res => setGlobalGraphData(res.data))
        .catch(err => console.error("Error loading graph dataset", err));
    }
  }, [activeTab]);

  useEffect(() => {
    if (activeTab === 'graph' && graphContainerRef.current) {
      const updateDim = () => {
        setGraphDim({
          width: graphContainerRef.current.clientWidth,
          height: graphContainerRef.current.clientHeight
        });
      };
      updateDim();
      setTimeout(updateDim, 50);
      window.addEventListener('resize', updateDim);
      return () => window.removeEventListener('resize', updateDim);
    }
  }, [activeTab]);

  const handleRunQuery = async () => {
    setIsLoading(true);
    setStatus('idle');
    setOutput('');
    setErrorDetails('');
    setParsedData(null);
    setActiveTab('raw');
    
    const startTime = performance.now();

    try {
      const response = await axios.post('http://localhost:3001/api/execute', { query });
      const endTime = performance.now();
      setExecutionTime(endTime - startTime);
      
      const { stdout, stderr, exitCode } = response.data;
      
      if (exitCode === 0) {
        setStatus('success');
        setOutput(stdout || 'Query executed successfully with no output.');
        if (stderr) setOutput(prev => prev + '\n[Warnings]:\n' + stderr);
        
        // Try to parse the output if it looks like the Row X: { ... } format
        parseCustomOutput(stdout);
      } else {
        setStatus('error');
        setOutput(stdout || '');
        setErrorDetails(stderr || `Process exited with code ${exitCode}`);
      }
    } catch (err) {
      const endTime = performance.now();
      setExecutionTime(endTime - startTime);
      setStatus('error');
      setErrorDetails(err.message || 'Failed to connect to the backend server.');
    } finally {
      setIsLoading(false);
    }
  };

  // Helper to try parsing the C++ engine's specific output format
  const parseCustomOutput = (stdout) => {
    if (!stdout) return;
    
    try {
      const lines = stdout.split('\n');
      const data = [];
      
      for (const line of lines) {
        // Look for "Row 1: { user_id: 101, name: Vaibhav }" format
        const match = line.match(/Row \d+:\s*\{(.*)\}/);
        if (match && match[1]) {
          const propsString = match[1].trim();
          const props = {};
          
          // Split by comma, but be careful of commas inside strings
          const pairs = propsString.split(/,\s*(?![^\[]*\])/);
          
          pairs.forEach(pair => {
            const [key, ...valueParts] = pair.split(':');
            if (key) {
               props[key.trim()] = valueParts.join(':').trim();
            }
          });
          data.push(props);
        }
      }
      
      if (data.length > 0) {
        setParsedData(data);
        setActiveTab('json'); // Auto-switch to parsed view if we found data
      }
    } catch (e) {
      console.warn("Could not auto-parse output", e);
    }
  };

  const handleClear = () => {
    setQuery('');
    setOutput('');
    setErrorDetails('');
    setStatus('idle');
    setExecutionTime(0);
    setParsedData(null);
  };

  return (
    <div className="app-container">
      <header className="header">
        <div className="logo-container">
          <div className="logo-icon">
            <Database size={20} strokeWidth={2.5} />
          </div>
          <div>
            <h1>GQL Studio</h1>
            <span className="subtitle">Graph Query Processing Engine</span>
          </div>
        </div>
        <div className="header-right">
          <button 
            className={`btn ${activeTab === 'graph' ? 'btn-primary' : 'btn-secondary'}`}
            style={{ marginRight: '8px' }}
            onClick={() => setActiveTab('graph')}
          >
            <Share2 size={14} /> Dataset Visualizer
          </button>
          {executionTime > 0 && (
            <div className="execution-time">
              <Clock size={14} className="text-muted" />
              <span>{executionTime.toFixed(2)} ms</span>
            </div>
          )}
          <div className={`status-badge ${status}`}>
            {status === 'success' && <><CheckCircle size={16} /> Success</>}
            {status === 'error' && <><AlertCircle size={16} /> Failed</>}
            {status === 'idle' && 'Ready'}
          </div>
        </div>
      </header>

      <main className="main-content">
        {/* LEFT PANE - EDITOR */}
        <div className="editor-pane glass-panel">
          <div className="pane-header">
            <div className="tab active-tab">
              <Terminal size={14} /> Query
            </div>
            <div className="actions">
              <button 
                className="btn btn-secondary" 
                onClick={handleClear}
                disabled={isLoading}
                title="Clear Editor"
              >
                <Eraser size={14} /> Clear
              </button>
              <button 
                className="btn btn-primary pulse-hover" 
                onClick={handleRunQuery}
                disabled={isLoading || !query.trim()}
              >
                {isLoading ? (
                  <span className="spinner"></span>
                ) : (
                  <><Play size={14} /> Execute</>
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
                fontSize: 15,
                lineHeight: 24,
                fontFamily: "'JetBrains Mono', 'Fira Code', Consolas, monospace",
                fontLigatures: true,
                padding: { top: 24 },
                smoothScrolling: true,
                cursorBlinking: 'smooth',
                cursorSmoothCaretAnimation: 'on',
                formatOnPaste: true,
              }}
            />
          </div>
        </div>

        {/* RIGHT PANE - RESULTS */}
        <div className="results-pane glass-panel">
          <div className="pane-header">
            <div className="tabs">
              <button 
                className={`tab ${activeTab === 'raw' ? 'active-tab' : ''}`}
                onClick={() => setActiveTab('raw')}
              >
                <Terminal size={14} /> Raw Output
              </button>
              <button 
                className={`tab ${activeTab === 'json' ? 'active-tab' : ''}`}
                onClick={() => setActiveTab('json')}
                disabled={!parsedData}
              >
                <Braces size={14} /> Parsed Data {parsedData && `(${parsedData.length})`}
              </button>
            </div>
          </div>
          
          <div className="results-wrapper">
            {status === 'idle' && !output && (
              <div className="empty-state">
                <div className="empty-icon-wrapper">
                  <Database size={32} />
                </div>
                <h3>Awaiting Instructions</h3>
                <p>Type your GQL query in the editor and hit Execute to see the engine's response.</p>
              </div>
            )}
            
            {(output || errorDetails) && (
              <div className="content-area animate-fade-in">
                {errorDetails && (
                  <div className="error-box">
                    <div className="error-header">
                      <AlertCircle size={16} />
                      <span>Parsing / Execution Error</span>
                    </div>
                    <pre className="stderr">{errorDetails}</pre>
                  </div>
                )}

                {activeTab === 'raw' && output && (
                  <div className="terminal-container">
                    <div className="terminal-top-bar">
                      <div className="mac-btns">
                        <span className="mac-btn close"></span>
                        <span className="mac-btn min"></span>
                        <span className="mac-btn max"></span>
                      </div>
                      <span className="terminal-title">gqlparser output</span>
                    </div>
                    <pre className="stdout">{output}</pre>
                  </div>
                )}

                {activeTab === 'json' && parsedData && (
                  <div className="parsed-grid">
                    {parsedData.map((row, idx) => (
                      <div key={idx} className="data-card">
                        <div className="card-header">Row {idx + 1}</div>
                        <div className="card-body">
                          {Object.entries(row).map(([key, val]) => (
                            <div key={key} className="data-row">
                              <span className="data-key">{key}</span>
                              <span className="data-value">{val}</span>
                            </div>
                          ))}
                        </div>
                      </div>
                    ))}
                  </div>
                )}

                {activeTab === 'graph' && (
                  <div className="graph-container" ref={graphContainerRef} style={{ width: '100%', height: '100%', minHeight: '400px', display: 'flex', position: 'relative', overflow: 'hidden', borderRadius: '10px', border: '1px solid var(--border-color)' }}>
                    {globalGraphData ? (
                      <ForceGraph2D
                        width={graphDim.width}
                        height={graphDim.height}
                        graphData={globalGraphData}
                        nodeLabel={(node) => node.properties?.name || node.properties?.category_name || node.id}
                        nodeAutoColorBy={(node) => node.labels?.[0]}
                        linkDirectionalParticles={2}
                        linkDirectionalParticleSpeed={0.01}
                        backgroundColor="#0d0f12"
                        nodeRelSize={8}
                        linkColor={() => 'rgba(255,255,255,0.2)'}
                      />
                    ) : (
                      <div className="empty-state">
                        <span className="spinner"></span>
                        <p>Loading Dataset...</p>
                      </div>
                    )}
                  </div>
                )}
              </div>
            )}
          </div>
        </div>
      </main>
      
      {/* Background decoration */}
      <div className="glow glow-1"></div>
      <div className="glow glow-2"></div>
    </div>
  );
}

export default App;
