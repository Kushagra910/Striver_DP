// 994. Rotting Oranges

// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

// here BFS algorithm is applied because we need to visit same level guys at same time so that time taken to rot all oranges 
// donot become large

// SC= O(n*m)
// TC = O(n*m) for storing in queue+ O(n*m*4) for every nodes we run for 4times
// aggregate TC = O(n*m)

class Solution {
    bool isValid(int nr,int nc,int n,int m,vector<vector<int>>&grid){
        if(nr>=0 && nr<n && nc>=0 && nc<m) return true;
        return false;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});      // here multiple starting points which are initial rotten oranges
                    vis[i][j] = 2;
                }
            }
        }
        int time = 0;
        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,1,0,-1};
        while(!q.empty()){
            auto temp = q.front();
            int curr_row = temp.first.first;
            int curr_col = temp.first.second;
            int tm = temp.second;
               q.pop();
            time = max(time,tm);
            for(int i=0;i<4;i++){  // how many neighbours do you have? ans = 4  
                int nr = curr_row+dr[i];
                int nc = curr_col+dc[i];
                if(isValid(nr,nc,n,m,grid) && vis[nr][nc] != 2 && grid[nr][nc] == 1 ){
                    vis[nr][nc] = 2;
                    q.push({{nr,nc},tm+1});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] != 2 && grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return time;
    }
};