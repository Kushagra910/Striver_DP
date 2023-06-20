// 931. Minimum Falling Path Sum

// Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
// A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

//  Recursive
// how many paths are you exploring
// TC = O(3*n)
// SC = O(n) rss

class Solution {
    private:
    int func(int row,int col,vector<vector<int>>& matrix){
        if(col<0 || col > matrix[0].size()-1) return 1e9;
        if(row == 0) return matrix[0][col];
        int up = matrix[row][col] + func(row-1,col,matrix);
        int ld = matrix[row][col] + func(row-1,col-1,matrix);
        int rd = matrix[row][col] + func(row-1,col+1,matrix);
        return min(up,min(ld,rd));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mini = INT_MAX;
        for(int col=0;col<matrix[0].size();col++){
            int sum =  func(n-1,col,matrix);
            mini = min(mini,sum);
        }
        return mini;
    }
};

// Memoization
// TC = O(n*n)
// SC = O(n*n) + O(n)

class Solution {
    private:
    int func(int row,int col,vector<vector<int>>& matrix,vector<vector<int>>&dp){
        if(col<0 || col > matrix[0].size()-1) return 1e9;
        if(row == 0) return matrix[0][col];
        if(dp[row][col] != -1) return dp[row][col];
        int up = matrix[row][col] + func(row-1,col,matrix,dp);
        int ld = matrix[row][col] + func(row-1,col-1,matrix,dp);
        int rd = matrix[row][col] + func(row-1,col+1,matrix,dp);
        return dp[row][col] = min(up,min(ld,rd));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int mini = INT_MAX;
        for(int col=0;col<matrix[0].size();col++){
            int sum =  func(n-1,col,matrix,dp);
            mini = min(mini,sum);
        }
        return mini;
    }
};

// Tabulation 
// TC = O(n*n)
// SC = O(n*n)

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,0));

        for(int col = 0;col<n;col++){
            dp[0][col] = matrix[0][col];
        }
        for(int row = 1;row<n;row++){
            for(int col = 0;col<n;col++){
                int up = matrix[row][col] + dp[row-1][col];
                int ld = matrix[row][col];
                if(col-1>=0) ld += dp[row-1][col-1];
                else ld += 1e9;
                int rd = matrix[row][col] ;
                if(col+1<n) rd += dp[row-1][col+1];
                else rd  += 1e9;
                dp[row][col] = min(up,min(ld,rd));
            }
        }
        int mini = INT_MAX;
        for(int col=0;col<matrix[0].size();col++){
            int sum =  dp[n-1][col];
            mini = min(mini,sum);
        }
        return mini;
    }