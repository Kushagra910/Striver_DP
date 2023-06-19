// 64. Minimum Path Sum
// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
// Note: You can only move either down or right at any point in time.

//Memoization
// TC = O(n*m)
// SC = O(n*m) + O(n-1+m-1)

class Solution {
public:

    int f(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&dp){
        if(i == 0 && j == 0) return grid[i][j];
        if(i<0 || j<0) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = grid[i][j]+f(i-1,j,grid,dp);
        int left = grid[i][j] + f(i,j-1,grid,dp);
        return dp[i][j] = min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,grid,dp);
    }
};


