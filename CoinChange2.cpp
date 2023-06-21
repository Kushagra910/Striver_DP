//518. Coin Change II

// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
// Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.
// You may assume that you have an infinite number of each kind of coin.
// The answer is guaranteed to fit into a signed 32-bit integer.

// Recursive
// TC = exponential
// SC = O(amount) if minCOin denomination is 1;

class Solution {
    private:
    int func(int ind,int target,vector<int>&coins){
        if(ind == 0) {
            if(target % coins[ind] == 0){
                return 1;
            }
            else{
                return 0;
            }
        }
        int notTake = func(ind-1,target,coins);
        int take = 0;
        if(coins[ind]<=target) take = func(ind,target-coins[ind],coins);
        return take + notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return func(n-1,amount,coins);
    }
};

// Memoized 
// TC = O(n*amount) 
// SC = O(n*amount) + O(amount)Ass

class Solution {
    private:
    int func(int ind,int target,vector<int>&coins,vector<vector<int>>&dp){
        if(ind == 0) {
            if(target % coins[ind] == 0){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[ind][target] != -1) return dp[ind][target];
        int notTake = func(ind-1,target,coins,dp);
        int take = 0;
        if(coins[ind]<=target) take = func(ind,target-coins[ind],coins,dp);
        return dp[ind][target] = take + notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return func(n-1,amount,coins,dp);
    }
};

// Tabulation bottom up
// TC = O(n*amount)
// SC = O(n*amount)

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        for(int tar=0;tar<=amount;tar++){
            if(tar % coins[0] == 0){
                dp[0][tar] = 1;
            }
            else dp[0][tar] = 0;
        }
        for(int ind=1;ind<n;ind++){
            for(int tar = 0;tar<=amount;tar++){
                int notTake = dp[ind-1][tar];
                int take = 0;
                if(coins[ind]<=tar) take = dp[ind][tar-coins[ind]];
                dp[ind][tar] = take + notTake;
            }
        }
        return dp[n-1][amount];
    }

    
