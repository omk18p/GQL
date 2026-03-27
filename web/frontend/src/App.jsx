import { useState, useEffect, useRef } from 'react';
import Editor from '@monaco-editor/react';
import axios from 'axios';
import { Play, Eraser, AlertCircle, CheckCircle, Database, Clock, Terminal, Braces, Share2, History, X, Trash2 } from 'lucide-react';
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
  const editorRef = useRef(null);
  const monacoRef = useRef(null);
  const [graphDim, setGraphDim] = useState({ width: 600, height: 400 });
  const [globalGraphData, setGlobalGraphData] = useState(null);
  const [selectedNode, setSelectedNode] = useState(null);
  const [hoveredNode, setHoveredNode] = useState(null);
  
  // History State
  const [history, setHistory] = useState(() => {
    const saved = localStorage.getItem('gql_query_history');
    return saved ? JSON.parse(saved) : [];
  });
  const [isHistoryOpen, setIsHistoryOpen] = useState(false);

  useEffect(() => {
    localStorage.setItem('gql_query_history', JSON.stringify(history));
  }, [history]);

  useEffect(() => {
    if (activeTab === 'graph') {
      setGlobalGraphData(null); // clear to show loader, then re-fetch
      axios.get('http://localhost:3001/api/dataset')
        .then(res => setGlobalGraphData(res.data))
        .catch(err => console.error("Error loading graph dataset", err));
    }
  }, [activeTab]);

  useEffect(() => {
    if (activeTab !== 'graph') return;

    const el = graphContainerRef.current;
    if (!el) return;

    const updateDim = () => {
      // ForceGraph2D relies on the explicit width/height props.
      setGraphDim({
        width: el.clientWidth,
        height: el.clientHeight
      });
    };

    updateDim();

    // Observe container size changes caused by tab switches/layout changes.
    let ro = null;
    if (typeof ResizeObserver !== 'undefined') {
      ro = new ResizeObserver(() => updateDim());
      ro.observe(el);
    } else {
      // Fallback for older browsers.
      window.addEventListener('resize', updateDim);
    }

    return () => {
      if (ro) ro.disconnect();
      window.removeEventListener('resize', updateDim);
    };
  }, [activeTab]);

  const handleRunQuery = async () => {
    setIsLoading(true);
    setStatus('idle');
    setOutput('');
    setErrorDetails('');
    setParsedData(null);
    setActiveTab('raw');
    
    // Clear previous markers
    if (monacoRef.current && editorRef.current) {
      monacoRef.current.editor.setModelMarkers(editorRef.current.getModel(), 'gql', []);
    }
    
    // Add to history
    if (query.trim()) {
      const newEntry = {
        id: Date.now(),
        query: query.trim(),
        timestamp: new Date().toISOString()
      };
      // Keep unique and limited to 50
      setHistory(prev => {
        const filtered = prev.filter(h => h.query !== query.trim());
        return [newEntry, ...filtered].slice(0, 50);
      });
    }

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
        
        // Error highlighting
        if (stderr && monacoRef.current && editorRef.current) {
          const errorLoc = parseErrorLocation(stderr);
          if (errorLoc) {
            const model = editorRef.current.getModel();
            monacoRef.current.editor.setModelMarkers(model, 'gql', [
              {
                startLineNumber: errorLoc.line,
                startColumn: errorLoc.column + 1,
                endLineNumber: errorLoc.line,
                endColumn: model.getLineMaxColumn(errorLoc.line),
                message: stderr.split('\n')[0],
                severity: monacoRef.current.MarkerSeverity.Error,
              }
            ]);
          }
        }
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
          const pairs = propsString.split(/,\s*(?![^[]*])/);
          
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

  const parseErrorLocation = (stderr) => {
    if (!stderr) return null;
    // Look for "line X:Y" pattern
    const match = stderr.match(/line (\d+):(\d+)/);
    if (match) {
      return {
        line: parseInt(match[1], 10),
        column: parseInt(match[2], 10)
      };
    }
    return null;
  };

  const handleClear = () => {
    setQuery('');
    setOutput('');
    setErrorDetails('');
    setStatus('idle');
    setExecutionTime(0);
    setParsedData(null);
    if (monacoRef.current && editorRef.current) {
      monacoRef.current.editor.setModelMarkers(editorRef.current.getModel(), 'gql', []);
    }
  };

  const handleReset = async () => {
    if (!window.confirm('Are you sure you want to reset the database? This will revert the graph to its initial state.')) {
      return;
    }

    setIsLoading(true);
    setStatus('idle');
    
    try {
      const response = await axios.post('http://localhost:3001/api/reset');
      if (response.data.success) {
        setStatus('success');
        handleClear();
        // If we are on graph tab, it will re-fetch due to setGlobalGraphData(null) in useEffect
        if (activeTab === 'graph') {
          setGlobalGraphData(null);
          const res = await axios.get('http://localhost:3001/api/dataset');
          setGlobalGraphData(res.data);
        } else {
          // Force a fetch anyway so it's ready when they switch
          const res = await axios.get('http://localhost:3001/api/dataset');
          setGlobalGraphData(res.data);
        }
        alert('Database reset successfully!');
      } else {
        setStatus('error');
        setErrorDetails(response.data.message || 'Failed to reset database');
      }
    } catch (err) {
      setStatus('error');
      setErrorDetails(err.response?.data?.message || err.message || 'Failed to connect to the backend server.');
    } finally {
      setIsLoading(false);
    }
  };

  const handleHistoryItemClick = (hQuery) => {
    setQuery(hQuery);
    setIsHistoryOpen(false);
  };

  const deleteHistoryItem = (id, e) => {
    e.stopPropagation();
    setHistory(prev => prev.filter(item => item.id !== id));
  };

  const clearHistory = () => {
    if (window.confirm('Are you sure you want to clear all query history?')) {
      setHistory([]);
    }
  };

  const handleEditorDidMount = (editor, monaco) => {
    editorRef.current = editor;
    monacoRef.current = monaco;
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
            className="btn btn-danger"
            style={{ marginRight: '8px' }}
            onClick={handleReset}
            disabled={isLoading}
            title="Reset Database to Initial State"
          >
            <Database size={14} /> Reset DB
          </button>
          <button 
            className={`btn btn-secondary ${isHistoryOpen ? 'active' : ''}`}
            onClick={() => setIsHistoryOpen(!isHistoryOpen)}
            title="Query History"
          >
            <History size={16} /> History
          </button>
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
        {/* HISTORY SIDEBAR */}
        <div className={`history-sidebar glass-panel ${isHistoryOpen ? 'open' : ''}`}>
          <div className="sidebar-header">
            <h3><History size={16} /> Query History</h3>
            <div className="sidebar-actions">
              {history.length > 0 && (
                <button className="btn-text" onClick={clearHistory}>Clear All</button>
              )}
              <button className="close-btn" onClick={() => setIsHistoryOpen(false)}>
                <span>×</span>
              </button>
            </div>
          </div>
          <div className="history-list">
            {history.length === 0 ? (
              <div className="empty-history">
                <Clock size={24} />
                <p>No history found</p>
              </div>
            ) : (
              history.map(item => (
                <div 
                  key={item.id} 
                  className="history-item"
                  onClick={() => handleHistoryItemClick(item.query)}
                >
                  <div className="history-item-content">
                    <pre>{item.query.substring(0, 100)}{item.query.length > 100 ? '...' : ''}</pre>
                    <span className="history-time">{new Date(item.timestamp).toLocaleString()}</span>
                  </div>
                  <button 
                    className="delete-item" 
                    onClick={(e) => deleteHistoryItem(item.id, e)}
                    title="Remove from history"
                  >
                    <Trash2 size={13} strokeWidth={2.5} />
                  </button>
                </div>
              ))
            )}
          </div>
        </div>

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
              onMount={handleEditorDidMount}
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
                <p>Type your GQL query in the editor and hit Execute to see the engine&apos;s response.</p>
              </div>
            )}
            
            {(output || errorDetails || activeTab === 'graph') && (
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
                  <div className="graph-wrapper">
                    <div className="graph-container-header">
                      <div className="graph-title">
                        <Share2 size={16} className="text-accent" />
                        <span>Interactive Dataset Map</span>
                      </div>
                      <div className="graph-stats">
                        {globalGraphData && (
                          <>
                            <span className="stat-badge">{globalGraphData.nodes?.length || 0} Nodes</span>
                            <span className="stat-badge">{globalGraphData.links?.length || 0} Relationships</span>
                          </>
                        )}
                      </div>
                    </div>
                    
                    <div className="graph-content" ref={graphContainerRef}>
                      {globalGraphData ? (
                        <>
                          <ForceGraph2D
                            width={graphDim.width}
                            height={graphDim.height}
                            graphData={globalGraphData}
                            nodeLabel={(node) => node.properties?.name || node.properties?.category_name || node.id}
                            nodeColor={(node) => {
                              const label = node.labels?.[0] || 'Unknown';
                              const colors = {
                                'Users': '#8b5cf6',
                                'Products': '#3b82f6',
                                'Categories': '#10b981',
                                'Orders': '#f59e0b',
                                'Reviews': '#ef4444'
                              };
                              return colors[label] || '#94a3b8';
                            }}
                            nodeRelSize={6}
                            linkDirectionalParticles={4}
                            linkDirectionalParticleSpeed={0.005}
                            linkWidth={1}
                            linkColor={() => 'rgba(255,255,255,0.1)'}
                            backgroundColor="transparent"
                            onNodeClick={(node) => setSelectedNode(node)}
                            onNodeHover={(node) => setHoveredNode(node)}
                            nodeCanvasObject={(node, ctx, globalScale) => {
                              const nodeLabel = node.properties?.name || node.properties?.category_name || node.id;
                              const fontSize = 12/globalScale;
                              ctx.font = `${fontSize}px Inter`;
                              // Compute color from label
                              const typeLabel = node.labels?.[0] || 'Unknown';
                              const colorMap = {
                                'Users': '#8b5cf6',
                                'Products': '#3b82f6',
                                'Categories': '#10b981',
                                'Orders': '#f59e0b',
                                'Reviews': '#ef4444'
                              };
                              const nodeColor = colorMap[typeLabel] || '#94a3b8';

                              // Node circle
                              const r = 4;
                              ctx.beginPath();
                              ctx.arc(node.x, node.y, r, 0, 2 * Math.PI, false);
                              ctx.fillStyle = nodeColor;
                              ctx.fill();
                              
                              if (hoveredNode === node || selectedNode === node) {
                                ctx.strokeStyle = '#fff';
                                ctx.lineWidth = 2/globalScale;
                                ctx.stroke();
                              }

                              // Label
                              if (globalScale > 1.5) {
                                ctx.fillStyle = 'rgba(255, 255, 255, 0.8)';
                                ctx.textAlign = 'center';
                                ctx.textBaseline = 'middle';
                                ctx.fillText(nodeLabel, node.x, node.y + r + fontSize);
                              }
                            }}
                          />
                          
                          {/* Legend */}
                          <div className="graph-legend">
                            <h4>Legend</h4>
                            <div className="legend-items">
                              {[...new Set(globalGraphData.nodes.map(n => n.labels?.[0] || 'Unknown'))].map(label => (
                                <div key={label} className="legend-item">
                                  <span className="legend-color" style={{ backgroundColor: 
                                    label === 'Users' ? '#8b5cf6' : 
                                     label === 'Products' ? '#3b82f6' : 
                                     label === 'Categories' ? '#10b981' : 
                                     label === 'Orders' ? '#f59e0b' : 
                                     label === 'Reviews' ? '#ef4444' : '#94a3b8' 
                                  }}></span>
                                  <span>{label}</span>
                                </div>
                              ))}
                            </div>
                          </div>

                          {/* Node Details Popup */}
                          {selectedNode && (
                            <div className="node-details-popup animate-fade-in">
                              <div className="popup-header">
                                <span>Node Details</span>
                                <button className="close-btn" onClick={() => setSelectedNode(null)}>×</button>
                              </div>
                              <div className="popup-content">
                                <div className="detail-row">
                                  <span className="detail-label">ID</span>
                                  <span className="detail-value">{selectedNode.id}</span>
                                </div>
                                <div className="detail-row">
                                  <span className="detail-label">Labels</span>
                                  <span className="detail-value">{selectedNode.labels?.join(', ')}</span>
                                </div>
                                <div className="divider"></div>
                                {selectedNode.properties && Object.entries(selectedNode.properties).map(([key, val]) => (
                                  <div key={key} className="detail-row">
                                    <span className="detail-label">{key}</span>
                                    <span className="detail-value">{String(val)}</span>
                                  </div>
                                ))}
                              </div>
                            </div>
                          )}
                        </>
                      ) : (
                        <div className="graph-loading">
                          <span className="spinner"></span>
                          <p>Mapping dataset connections...</p>
                        </div>
                      )}
                    </div>
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
