// Grap can be stored in a matrix
// but we will not use this much because its SC = O(n^2) in storing 
// TC = O(m)

int main(){

    int n,m;
    cin>>n>>m;
    int adjacencyMatrix[n+1][n+1]; // considering one base indexing
    for(int i=0;i<m;i++){
    int u,v;
    cin>>u >> v;
    adjacencyMatrix[u][v] = 1;
    adJacencyMatrix[v][u] = 1;   // given graph is undirected
  }
  return 0;
}


// ADJACENCY list
// SC = O(2*E) where E is total number of edges given graph is undirected
// SC = O(E) when graph is directed
// TC = O(m)

int main(){
  int n,m;
  cin >> n>> m;
  vector<int>adj[n+1];  // considering one base indexing
  for(int i=0;i<m;i++){
    int u,v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  return 0;
}