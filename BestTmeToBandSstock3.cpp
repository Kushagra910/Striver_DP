// 123. Best Time to Buy and Sell Stock III

// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// Find the maximum profit you can achieve. You may complete at most two transactions.
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

// Since here we are Bounded by only Two Transactions instead of infinite 
// So we just introduce a new state for atmost 2 transactions
// and our question become a modified version of Best Time to buy and sell stocks 2 
// Here our cap is reduced only when one transaction is fully completed

// Memoization -- > TLE
// TC =O(n x 2 x 3)
// SC = O(n x 2 x 3) + O(n)
class Solution {
    int func(int idx,int buy,int cap,vector<int>&prices,int n,vector<vector<vector<int>>>dp){
        if(idx == n ) return 0;
        if(cap == 0) return 0;
        if(dp[idx][buy][cap] != -1) return dp[idx][buy][cap];
        int profit = 0;
        if(buy){
            profit = max(-prices[idx] + func(idx+1,0,cap,prices,n,dp),0+func(idx+1,1,cap,prices,n,dp));
        }
        else{
            profit = max(prices[idx] + func(idx+1,1,cap-1,prices,n,dp),0+func(idx+1,0,cap,prices,n,dp));
        }
        return dp[idx][buy][cap] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return func(0,1,2,prices,n,dp);
    }
};

// Tabulation

// TC =O(n x 2 x 3)
// SC = O(n x 2 x 3)
// here base cases were not required as they were already filled with 0
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        // First Base case -> if cap = 0 , idx and buy can be anything
        for(int i = 0;i<n;i++){
            for(int buy = 0;buy<=1;buy++){
                dp[i][buy][0] = 0;
            }
        }
        // if idx = n , buys and cap can be anything
        for(int buy = 0;buy<=1;buy++){
            for(int cap = 0;cap<=2;cap++){
                dp[n][buy][cap] = 0;
            }
        }
        
        for(int idx = n-1;idx>=0;idx--){
            for(int buy = 0;buy<=1;buy++){
                for(int cap = 1;cap<=2;cap++){   // ignore cap = 0 because it is always zero
                    int profit = 0;
                    if(buy == 1){
                        profit = max(-prices[idx] + dp[idx+1][0][cap],0+dp[idx+1][1][cap]);
                    }
                    else{
                        profit = max(prices[idx] + dp[idx+1][1][cap-1],0+dp[idx+1][0][cap]);
                    }
                    dp[idx][buy][cap] = profit;
                 }
            }
        }
        return dp[0][1][2];
    }
