// Detect cycle in an undirected graph

// Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not.
//  Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.

// Intution - we started from some where and if we reach any node which has been previously visited means
// a cyle is present . so we have to keep a track of parent node.

// Using DFS
// TC =O(V) + O(V+2*E)
// SC =O(V)+O(V) rss+vis
class Solution {
    private:
    bool dfs(int src,int prev,vector<int>&vis,vector<int>adj[]){
        vis[src] = 1;
        for(auto it:adj[src]){
            
            if(!vis[it]){
                if( dfs(it,src,vis,adj) == true){
                    return true;
                }
            }
            else if(it!=prev) return true;
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,-1,vis,adj) == true){
                    return true;
                }
            }
        }
        return false;
    }
};