// Detect Cycle in a Directed Graph using Kahn's Algorithm

// Problem Statement
// Given a directed graph, check whether the graph contains a cycle or not.
//  Your function should return true if the given graph contains at least one cycle, else return false.


// Using Modified BFS

// TC = O(V+E)
// SC = O(V) overall
#include<bits/stdc++.h>

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  vector<int>adj[n+1];
  for(auto &edge:edges){
    int u = edge.first;
    int v = edge.second;
    adj[u].push_back(v);
  }
  vector<int>indegree(n+1,0);
  for(int i=1;i<=n;i++){
    for(auto it:adj[i]){
      indegree[it]++;
    }
  }
  queue<int>q;
  for(int i=1;i<=n;i++){
    if(indegree[i] == 0){
      q.push(i);
    }
  }
  int cnt = 0;
  while(!q.empty()){
    int node = q.front();
    q.pop();
    cnt++;
    for(auto it:adj[node]){
      indegree[it]--;
      if(indegree[it]  == 0){
        q.push(it);
      }
    }
  }
  if(cnt == n){
    return 0;
  }
  return 1;
}