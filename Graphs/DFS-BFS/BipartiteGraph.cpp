// 785. Is Graph Bipartite?

// we need to color the graph with 2 colors such that no adjacent nodes have the same color
// intution comes from coloring and observing the question
// Some Observation can be made or property for bipartite
// Applyin BFS 



// TC =  O(n + 2*E)
// SC = O(n) overall

class Solution {

private:
    bool bfs(int source,vector<vector<int>>& graph,vector<int>&color){
        queue<int>q;
        q.push(source);
        color[source] = 0;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            for(auto it:graph[node]){
                if(color[it] == -1){
                    q.push(it);
                    color[it] = !color[node];
                }
                // if the adjacent node is having the same color means
                // someone did color it on some other path
                else if(color[it] == color[node]){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i] == -1){
                if(bfs(i,graph,color) == false){
                    return false;
                }
            }
        }
        return true;
    }
};