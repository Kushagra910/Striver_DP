// 322. Coin Change leetCode

// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
// You may assume that you have an infinite number of each kind of coin.

// RECURSIVE
// TC = exponential
// SC = O(amount) when minimum Denomination is assumed 1

class Solution {
    int func(int ind,int tar,vector<int>&coins){
        if(ind==0){
        if(tar % coins[0]==0) return tar/coins[ind];
        else return 1e9;
        }
        int notTake = 0+func(ind-1,tar,coins);
        int take = 1e9;
        if(coins[ind]<=tar){
            take = 1 + func(ind,tar-coins[ind],coins);
        }
        return min(take,notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans =func(n-1,amount,coins);
        if(ans>=1e9) return -1;
        return ans;
    }
};

// Memoized 
// TC = O(n*amount)
// SC = O(n*amount) + O(amount)

class Solution {
    int func(int ind,int tar,vector<int>&coins,vector<vector<int>>&dp){
        if(ind==0){
        if(tar % coins[0]==0) return tar/coins[ind];
        else return 1e9;
        }
        if(dp[ind][tar] != -1) return dp[ind][tar];
        int notTake = 0+func(ind-1,tar,coins,dp);
        int take = 1e9;
        if(coins[ind]<=tar){
            take = 1 + func(ind,tar-coins[ind],coins,dp);
        }
        return dp[ind][tar] =  min(take,notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans =func(n-1,amount,coins,dp);
        if(ans>=1e9) return -1;
        return ans;
    }
};

// Tabulation 
// TC = O(n*amount)
// SC = O(n*amount)

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        for(int tar = 0;tar <=amount;tar++){
            if(tar % coins[0] == 0){
                dp[0][tar] = tar/coins[0];
            }
            else{
                dp[0][tar] = 1e9;
            }
        }

        for(int ind=1;ind<n;ind++){
            for(int tar = 0;tar<=amount;tar++){
                int notTake = 0+dp[ind-1][tar];
                int take = 1e9;
                if(coins[ind]<=tar){
                    take = 1 + dp[ind][tar-coins[ind]];
                }
                dp[ind][tar] =  min(take,notTake);
            }
        }
        int ans = dp[n-1][amount];
        if(ans>=1e9) return -1;
        return ans;
    }