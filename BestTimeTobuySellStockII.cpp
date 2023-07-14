// 122. Best Time to Buy and Sell Stock II

// You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.
// Find and return the maximum profit you can achieve.

// MEMOIZATION
// TC = O(n x 2)
// SC = O(n x 2) + O(N)
class Solution {
    int func(int idx,int buy,vector<int>&prices,int n,vector<vector<int>>&dp){
        if(idx == n ) return 0;
        if(dp[idx][buy] != -1) return dp[idx][buy];
        int profit = 0;
        if(buy){
            profit = max(-prices[idx] + func(idx+1,0,prices,n,dp),0+func(idx+1,1,prices,n,dp));
        }
        else{
            profit = max(prices[idx] + func(idx+1,1,prices,n,dp),0+func(idx+1,0,prices,n,dp));
        }
        return dp[idx][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return func(0,1,prices,n,dp);
    }
};

// TABULATION
// SC = O(n x 2)
// TC = O(n x 2)

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        dp[n][0] = 0;
        dp[n][1] = 0;
        for(int i=n-1;i>=0;i--){
            for(int buy = 0;buy<2;buy++){
                int profit = 0;
                if(buy){
                    profit = max(-prices[i] + dp[i+1][0],0+dp[i+1][1]);
                }
                else{
                    profit = max(prices[i] + dp[i+1][1],0+dp[i+1][0]);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }

    // SPACE OPTIMIZATION
    // TC = O(n x 2)
    // SC = O(1)

        int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>curr(2,0),next(2,0);
        next[0] = 0;
        next[1] = 0;
        for(int i=n-1;i>=0;i--){
            for(int buy = 0;buy<2;buy++){
                int profit = 0;
                if(buy){
                    profit = max(-prices[i] + next[0],0+next[1]);
                }
                else{
                    profit = max(prices[i] +next[1],0+next[0]);
                }
                curr[buy] = profit;
            }
            next = curr;
        }
        return curr[1];
    }