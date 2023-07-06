// DFS of Graph
// You are given a connected undirected graph. Perform a Depth First Traversal of the graph.
// Note: Use a recursive approach to find the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph.

// SC = O(3*n)
// TC = O(n+2*E) E is total number of edges
class Solution {
  public:
    void func(int start,vector<int>&dfs,vector<int>&vis,vector<int>adj[]){
        vis[start] = 1;
        dfs.push_back(start);
        for(auto it:adj[start]){
            if(!vis[it]){
                func(it,dfs,vis,adj);
            }
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>dfs;
        vector<int>vis(V,0);
        int source = 0;
        func(source,dfs,vis,adj);
        return dfs;
    }
};