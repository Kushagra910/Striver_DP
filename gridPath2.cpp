//Grid Path 2 GFG
// You are given a grid of n * m having 0 and 1 respectively, 0 denotes space, and 1 denotes obstacle. Geek is located at top-left corner (i.e grid[0][0]) and wants to reach the bottom right corner of the grid.
//  A geek can move either down or right at any point of time. return the total number of ways in which Geek can reach bottom right corner. answer may be large take the modulo by 1e9+7.

// Memoization
// TC = O(n*m)
// SC = O(n*m) + O(n-1+m-1);
int mod = (int) 1e9+7;
class Solution {
    
    int func(int row,int col,vector<vector<int>>&dp,vector<vector<int>>& grid){
        if(row>=0 and col>=0 and grid[row][col] ==1) return 0;
        if(row == 0 and col == 0){
            return 1;
        }
        if(row<0 or col <0){
            return 0;
        }
        if(dp[row][col] != -1) return dp[row][col];
        int left = 0;
        if(col>0)left = func(row,col-1,dp,grid);
        int up = 0;
        if(row>0) up = func(row-1,col,dp,grid);
        return dp[row][col] = (left + up)%mod;
    }
  public:
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        // Code here
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return func(n-1,m-1,dp,grid);
    }
};
