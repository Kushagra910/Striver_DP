// TopoLogical Sort using BFS is Kahn's Algorithm


// Given a DAG(direct acyclic graph), print Topological Sorting of a given graph
// Any linear ordering of vertices of a graph such  that if there is a edge btw u and v , u should appear before v 
// this is the defination of TOPO sort
// Indegree Concept is Introduced here and how to calculate it  and store it

// TC = O(V+E) for BFS
// SC = O(V) overall
#include<bits/stdc++.h>
vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    // Write your code here!
    vector<int>adj[nodes];
    for(int i=0;i<edges;i++){
        int u = graph[i][0];
        int v = graph[i][1];
        adj[u].push_back(v);
    }
    vector<int>indegree(nodes,0);

    for(int i=0;i<nodes;i++){           // way to fill indegree vector
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }

    queue<int>q;
    for(int i=0;i<indegree.size();i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    vector<int>topoSort(nodes,0);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topoSort.push_back(node);
        // Node is in our TopoSort so remove it from indegree
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }
    return topoSort;
}
