// Find the number of islands

// Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.
// Note: An island is either surrounded by water or boundary of grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

// DFS Approach

// SC = O(n*m) + O(n*m);
// TC = O(n*m) + O(n*m*9);
class Solution {
    void dfs(int row,int col,vector<vector<char>>&grid,vector<vector<int>>&vis,int n,int m){
        vis[row][col] = 1;
        for(int delrow = -1;delrow<=+1;delrow++){
            for(int delcol = -1;delcol<=+1;delcol++){
                int nrow = row+delrow;
                int ncol = col + delcol;
                if(nrow>=0 && nrow<n and ncol>=0 and ncol<m and grid[nrow][ncol] == '1' and vis[nrow][ncol] == 0){
                    dfs(nrow,ncol,grid,vis,n,m);
                }
            }
        }
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && !vis[i][j] ){
                    dfs(i,j,grid,vis,n,m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};