// BFS of graph

// Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
// Note: One can move from node u to node v only if there's an edge from u to v. Find the BFS traversal of the graph starting from the 0th vertex, from left to right according to the input graph. 
// Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.


// TC = O(3*n)
// SC = O(n+2*E) considering 1 based indexing

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>bfs;
        vector<int>vis(V,0);
        queue<int>q;
        q.push(0);
        vis[0] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            vis[node] = 1;
            for(auto it:adj[node]){
                if(vis[it] == 0){
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        return bfs;
    }
};