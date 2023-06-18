
// Leetcode - 70
// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?


// Recursive 
// TC = exponential
// SC = O(N) rss

    int recursive(int ind){
        if(ind==0) return 1;
        if(ind==1) return 1;
        int j1=recursive(ind-1);
        int j2=recursive(ind-2);
        return j1+j2;
    }

// Memoization 
// TC = O(n);
// SC = O(n) + O(n)
class Solution {
    int solve(int ind,vector<int>&dp){
        if(ind==0) return 1;
        if(ind==1) return 1;
        if(dp[ind]!=-1) return dp[ind];
        int j1=solve(ind-1,dp);
        int j2=solve(ind-2,dp);
        return dp[ind]=j1+j2;
    }
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};


// tabulation 
// TC = O(n)
// SC = O(n)

    int climbStairs(int n) {
        vector<int>dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }