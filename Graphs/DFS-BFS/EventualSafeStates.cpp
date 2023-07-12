// 802. Find Eventual Safe States

// There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].
// A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).
// Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

//  you should know how to find a cycle in directed graph
//  and this is the intution - we use cycle detection concept (if any node is a part of the cycle then it will never be a safe node)
// --> Any Node that leads to a cycle cannot be a safe node else all are safe node

//DFS
// TC = O(V+E) 
// SC = O(3*v)
class Solution {
    bool dfs(int source,vector<vector<int>>& graph,vector<int>&vis,vector<int>&path_visited,vector<int>&check){
        vis[source] = 1;
        path_visited[source] = 1;
        check[source] = 0;
        for(auto it:graph[source]){
            if(!vis[it]){  // when nodes are not visited
                if(dfs(it,graph,vis,path_visited,check) == true) {
                    check[source] = 0;    // means for node on it you get a cycle so marked not possible
                    return true;
                }
            }
            else if(path_visited[it]){
                check[source] = 0;// this is not required because initialised earlier
                return true;
            }
        }
        check[source] = 1;
        path_visited[source] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>ans;
        int n =graph.size();
        vector<int>vis(n,0);
        vector<int>path_visited(n,0);
        vector<int>check(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,graph,vis,path_visited,check);
            }
        }
        for(int i = 0;i<n;i++){
            if(check[i] == 1) ans.push_back(i);
        }
        return ans;
    }
};
Console
