// Knapsack with Duplicate Items

// Given a set of N items, each with a weight and a value, represented by the array w[] and val[] respectively. Also, a knapsack with weight limit W.
// The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
// Note: Each item can be taken any number of times.

// Memoized 
// TC = O(N*W)
// SC = O(N*W) + O(W);


class Solution{
    int func(int ind,int bagW,int val[],int wt[],vector<vector<int>>&dp){
        if(ind == 0) {
             return  ((int)(bagW/wt[0]))*val[0];
        }
        if(dp[ind][bagW] != -1) return dp[ind][bagW];
        int notPick = 0 + func(ind-1,bagW,val,wt,dp);
        int pick = INT_MIN;
        if(wt[ind] <= bagW){
            pick = val[ind] + func(ind,bagW-wt[ind],val,wt,dp);
        }
        return dp[ind][bagW] = max(pick,notPick);
    }
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(N,vector<int>(W+1,-1));
        return func(N-1,W,val,wt,dp);
    }
};