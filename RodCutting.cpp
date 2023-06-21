// Rod Cutting GFG

// Given a rod of length N inches and an array of prices, price[].
//  price[i] denotes the value of a piece of length i. Determine the maximum value obtainable by cutting up the rod and selling the pieces.
// Note: Consider 1-based indexing.

// from observation can i say how can we collect Rod lengths to make N , and maximize the price

// memoization

class Solution{
    int func(int ind,int tar,int price[],vector<vector<int>>&dp){
        if(ind == 0) return tar*price[ind];
        if(dp[ind][tar] != -1) return dp[ind][tar];
        int notTake = 0 + func(ind-1,tar,price,dp);
        int take = INT_MIN;
        int rodLength = ind+1;
        if(rodLength<=tar) take = price[ind] + func(ind,tar-rodLength,price,dp);
        return dp[ind][tar] = max(take,notTake);
    }
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return func(n-1,n,price,dp);
    }
};