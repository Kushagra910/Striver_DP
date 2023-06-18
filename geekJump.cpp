#include <bits/stdc++.h>
using namespace std;


// Memoization 
// TC = O(n);
// SC = O(n) + O(n);
class Solution {
    int f(int ind,vector<int>& height,vector<int>&dp){
        if(ind == 0 ) return 0;
        if(dp[ind] != -1) return dp[ind];
        int fs = f(ind - 1,height,dp) + abs(height[ind] - height[ind-1]);
        int ss = INT_MAX;
        if(ind>1){
            ss = f(ind - 2,height,dp) + abs(height[ind] - height[ind-2]);
        }
        return dp[ind] = min(fs,ss);
    }
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int>dp(n,-1);
        return f(n-1,height,dp);
    }
};


// Tabulation - bottom UP
// TC = O(N)
// SC = O(N)

    int minimumEnergy(vector<int>& height, int n) {
        vector<int>dp(n);
        dp[0] = 0;
        for(int i=1;i<n;i++){
            int fs = dp[i-1] + abs(height[i] - height[i-1]);
            int ss = INT_MAX;
            if(i>1){
                 ss = dp[i-2] + abs(height[i] - height[i-2]);
            }
            dp[i] = min(fs,ss);
        }
        return dp[n-1];
    }

// Space Optimization
// TC = O(n)
// SC = O(1)

    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        int prev2 = 0;
        int prev1 = 0;
        for(int i=1;i<n;i++){
            int fs = prev1 + abs(height[i] - height[i-1]);
            int ss = INT_MAX;
            if(i>1){
                 ss = prev2 + abs(height[i] - height[i-2]);
            }
            int curr = min(fs,ss);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }