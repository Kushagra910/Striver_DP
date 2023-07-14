// Topological Sorting CodeStudio

// Given a DAG(direct acyclic graph), print Topological Sorting of a given graph
// Any linear ordering of vertices of a graph such  that if there is a edge btw u and v , u should appear before v 
// this is the defination of TOPO sort

// Intuition = Simply putting nodes in stack after the dfs traversal for that node is over

// TC = O(V + E) DFS
// SC = O(V) + O(V) + O(V) for stack,vis,rss
#include <bits/stdc++.h>

void dfs(int node,vector<int>adj[],vector<int>&vis,stack<int>&st){
    vis[node] = 1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,st);
        }
    }
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    // Write your code here!
    vector<int>adj[nodes];
    for(int i=0;i<edges;i++){
        int u = graph[i][0];
        int v = graph[i][1];
        adj[u].push_back(v);
    }
    stack<int>st;
    vector<int>vis(nodes,0);
    for(int i=0;i<nodes;i++){
        if(!vis[i]){
            dfs(i,adj,vis,st);
        }
    }
    vector<int>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
