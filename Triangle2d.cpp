// 120. Triangle - Leetcode
// Given a triangle array, return the minimum path sum from top to bottom.
// For each step, you may move to an adjacent number of the row below. More formally, 
// if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

// Recursive 
// TC = exponential
// SC= O(n) rss
// we have started with 0,0 because ending points was not fixed and for that 4 recurrence was required

class Solution {
    int func(int row,int col,vector<vector<int>>&triangle){
        int n =triangle.size();
        if(row == n-1) return triangle[n-1][col];
        int down = triangle[row][col] + func(row+1,col,triangle);
        int diag = triangle[row][col] + func(row+1,col+1,triangle);
        return min(down,diag);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        return func(0,0,triangle);
    }
};

// Memoization top-down
// TC = O(n*n)
// SC = O(n) + O(n*n)
class Solution {
    int func(int row,int col,vector<vector<int>>&triangle,vector<vector<int>>&dp){
        int n =triangle.size();
        if(row == n-1) return triangle[n-1][col];
        if(dp[row][col] != -1) return dp[row][col];
        int down = triangle[row][col] + func(row+1,col,triangle,dp);
        int diag = triangle[row][col] + func(row+1,col+1,triangle,dp);
        return dp[row][col]  = min(down,diag);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return func(0,0,triangle,dp);
    }
};

// Tabulation bottom-up
//TC = O(n*n)
// SC = O(n*n)

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int j=0;j<n;j++){
            dp[n-1][j] = triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down = triangle[i][j] + dp[i+1][j];
                int diag = triangle[i][j] + dp[i+1][j+1];
                dp[i][j]  = min(down,diag);
            }
        }
        return dp[0][0];
    }

// Space Optimization
// TC =O(n*n)
// SC = O(n)

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        vector<int>next(n,0);
        for(int j=0;j<n;j++){
            next[j] = triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            vector<int>curr(n,0);
            for(int j=i;j>=0;j--){
                int down = triangle[i][j] + next[j];
                int diag = triangle[i][j] + next[j+1];
                curr[j]  = min(down,diag);
            }
            next = curr;
        }
        return next[0];
    }
