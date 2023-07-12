// Detect Cycle in a Directed Graph

// Problem Statement
// Given a directed graph, check whether the graph contains a cycle or not.
//  Your function should return true if the given graph contains at least one cycle, else return false.


// TC = O(V+E) DFS
// SC =O(V)+O(V)+O(V) = O(V) overall

bool dfs(int node,vector<int>&vis,vector<int>&pathVisited,vector<int>adj[]){
	vis[node] = 1;
	pathVisited[node] = 1;
	for(auto adjele:adj[node]){
		if(!vis[adjele]){
			if(dfs(adjele,vis,pathVisited,adj) == true) return true;
		}
		else if(pathVisited[adjele]){
			return true;
		}
	}
	pathVisited[node] = 0;
	return false;
}

bool isCyclic(vector<vector<int>>& edges, int v, int e)
{
	// Write your code here
	vector<int>adj[v];
	for(int i=0;i<e;i++){
		int u = edges[i][0];
		int v = edges[i][1];
		adj[u].push_back(v);
	}
        vector<int>vis(v,0);
        vector<int>pathVisited(v,0);
        for(int i=0;i<v;i++){
            if(vis[i] == 0){
                if(dfs(i,vis,pathVisited,adj)){
                    return true;
                }
            }
        }
        return false;
}
