// 1020. Number of Enclaves

// You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
// A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
// Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

// Same Concept of Surrounded Regions

// TC = O(n)+ O(m) + O(n*m*4)
// SC = O(n*m) + O(n*m) = O(n*m)
class Solution {
private:

    int delrow[4] = {-1,0,1,0};
    int delcol[4] = {0,1,0,-1};
    bool isValid(int r,int c,vector<vector<int>>& grid,vector<vector<int>>&vis,int n,int m){
        if(r>=0 and r<n and c>=0 and c<m and !vis[r][c] and grid[r][c] == 1){
            return true;
        }
        return false;
    }
    void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>&vis,int n,int m){
        vis[row][col] = 1;
        for(int i=0;i<4;i++){
            int nrow = row+delrow[i];
            int ncol = col + delcol[i];
            if(isValid(nrow,ncol,grid,vis,n,m)){
                dfs(nrow,ncol,grid,vis,n,m);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            // check for first row
            if(!vis[0][i] and grid[0][i] == 1){
                dfs(0,i,grid,vis,n,m);
            }
            // check for last row
            if(!vis[n-1][i] and grid[n-1][i] == 1){
                dfs(n-1,i,grid,vis,n,m);
            }
        }
        for(int j=0;j<n;j++){
            // check for first column
            if(!vis[j][0] and grid[j][0] == 1){
                dfs(j,0,grid,vis,n,m);
            }
            if(!vis[j][m-1] and grid[j][m-1] == 1){
                dfs(j,m-1,grid,vis,n,m);
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and grid[i][j] == 1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};