// Chocolates Pickup - GFG


// You are given an r rows and c cols matrix grid representing a field of chocolates where grid[i][j] represents the number of chocolates that you can collect from the (i, j) cell.
// You have two robots that can collect chocolates for you:

// Robot #1 is located at the top-left corner (0, 0), and
// Robot #2 is located at the top-right corner (0, cols - 1).
// Return the maximum number of chocolates collection using both robots by following the rules below:

// From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
// When any robot passes through a cell, It picks up all chocolates, and the cell becomes an empty cell.
// When both robots stay in the same cell, only one takes the chocolates.
// Both robots cannot move outside of the grid at any moment.
// Both robots should reach the bottom row in grid.


// Recursion
// TC = O(3^n X 3^m) or exponential
// SC = O(n)


// Memoization 
// TC = O(n*m*m)*9
// SC = O(n*m*m) + O(n)


class Solution {
    int func(int row,int col1,int col2,vector<vector<int>>&grid,int n,int m, vector<vector<vector<int>>>&dp){
        if(col1<0 or col1>=m or col2<0 or col2>=m) return -1e8;
        if(row == n-1){
            if(col1 == col2) return grid[row][col1];
            else{
                return grid[row][col1]+grid[row][col2];
            }
        }
        if(dp[row][col1][col2] != -1) return dp[row][col1][col2];
        int maxi = INT_MIN;
        for(int dc1 = -1;dc1<=+1;dc1++){
            for(int dc2 = -1;dc2<=+1;dc2++){
                int val = 0;
                if(col1 == col2) val = grid[row][col1];
                else val = grid[row][col1] + grid[row][col2];
                val += func(row+1,col1+dc1,col2+dc2,grid,n,m,dp);
                maxi = max(maxi,val);
            }
        }
        return  dp[row][col1][col2] = maxi;
    }
  public:
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return func(0,0,m-1,grid,n,m,dp);
    }
};