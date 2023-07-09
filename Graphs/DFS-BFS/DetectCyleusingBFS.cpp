// Detect cycle in an undirected graph

// Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not.
//  Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.

// Using BFS
// Intution - if we start from same node but in two different path and if we colloid again some where in future means 
// cycle is present

// Try to name variable properly otherwise it may confuse you

// TC = O(V+2*E) + O(V) because for every node we are traversing all its adjacent node 
// SC = O(V)
class Solution {
    private:
    bool bfs(int src,int prev,vector<int>&vis,vector<int>adj[]){
        vis[src] = 1;
        queue<pair<int,int>>q;
        q.push({src,-1});
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it,node});
                }
                else if(it!=parent){
                    return true;
                }
            }
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
                if(bfs(i,-1,vis,adj) == true){
                    return true;
                }
            }
        }
        return false;
    }
};