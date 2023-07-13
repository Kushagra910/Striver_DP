// Course Schedule II

// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

// Same as CourseSchedule I but we have to return topo sort so we use Kahn's Algo 

// TC = O(n + E)
// SC = O(n) overall
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int>adj[n];
        for(auto it:prerequisites){
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
        }
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        vector<int>topoSort;
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            topoSort.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(topoSort.size() == n) return topoSort;
        else return {};
    }
};