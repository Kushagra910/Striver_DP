// Number of Unique Paths GFG
//Given a A X B matrix with your initial position at the top-left cell,
//find the number of possible unique paths to reach the bottom-right cell of the matrix from the initial position.
// Possible moves can be either down or right at any point in time

// Recursive 
// TC = 2^(a*b)
// SC = O(path length) or O(a-1+b-1);

// Memoization
//  TC = O(a*b)
// O(a-1+b-1) + O(a*b)

class Solution
{
    private:
    int func(int row,int col,vector<vector<int>>&dp){
        if(row == 0 and col == 0){
            return 1;
        }
        if(row<0 or col <0){
            return 0;
        }
        if(dp[row][col] != -1) return dp[row][col];
        int left = func(row,col-1,dp);
        int up = func(row-1,col,dp);
        return dp[row][col] = left + up;
    }
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        //code here
        vector<vector<int>>dp(a,vector<int>(b,-1));
        return func(a-1,b-1,dp);
    }
};

// Tabulation 
// TC = O(a*b)
// SC = O(a*b)

int NumberOfPath(int a, int b)
    {
        //code here
        vector<vector<int>>dp(a,vector<int>(b,0));
        dp[0][0] = 1;
        for(int row=0;row<a;row++){
            for(int col=0;col<b;col++){
                if(row == 0 and col==0){
                    dp[row][col] = 1;
                }
                else{
                    int left = 0;
                    if(col>0){
                         left = dp[row][col-1];
                    }
                    int up = 0;
                    if(row>0) up = dp[row-1][col];
                    dp[row][col] = left + up;                   
                }
            }
        }
        return dp[a-1][b-1];
    }

    //SpaceOptimization
    // TC = O(a*b)
    // SC = O(b);

        int NumberOfPath(int a, int b)
    {
        //code here
        // vector<vector<int>>dp(a,vector<int>(b,0));
        vector<int>prev(b,0);
        // prev[0] = 1;
        for(int row=0;row<a;row++){
            vector<int>temp(b,0);
            for(int col=0;col<b;col++){
                if(row == 0 and col == 0){
                    temp[col] = 1;
                }
                else{
                    int left = 0;
                    if(col>0){
                         left = temp[col-1];
                    }
                    int up = 0;
                    if(row>0) up = prev[col];
                    temp[col] = left + up;                   
                }
            }
            prev = temp;
        }
        return prev[b-1];
    }