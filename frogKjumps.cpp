// Follow up question of geekJump/frog jump where you are allowed to take K jumps

// Recursive 
// TC = O(exponential)*k
// SC = O(N);

class Solution {
    int func(int ind,vector<int>&height,int k){
        if(ind == 0) return 0;
        int minCost = INT_MAX;
         int jumps;
        for(int j=1;j<=k;j++){
            if(ind - j>= 0){
                 jumps = func(ind-j,height,k) + abs(height[ind] - height[ind-j]);
                  minCost = min(minCost,jumps);
            }
        }
        return minCost;
    }
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        return func(n-1,height,k);
    }
};

//Memoization Topdown
// TC = O(N*K)
// SC = O(N) + O(N)

class Solution {
    int func(int ind,vector<int>&height,int k,vector<int>&dp){
        if(ind == 0) return 0;
        if(dp[ind] != -1) return dp[ind];
        int minCost = INT_MAX;
         int jumps;
        for(int j=1;j<=k;j++){
            if(ind - j>= 0){
                 jumps = func(ind-j,height,k,dp) + abs(height[ind] - height[ind-j]);
                  minCost = min(minCost,jumps);
            }
        }
        return dp[ind] =  minCost;
    }
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector<int>dp(n,-1);
        return func(n-1,height,k,dp);
    }
};

 
// Tabulation = bottom up
// TC = O(n*k);
// SC = O(n);

class Solution {
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector<int>dp(n);
        dp[0] = 0;
        for(int i=1;i<n;i++){
            int minCost = INT_MAX;
            int jumps;
            for(int j=1;j<=k;j++){
                if(i - j >= 0){
                    jumps = dp[i - j] + abs(height[i] - height[i-j]);
                     minCost = min(minCost,jumps);
                }
            }
            dp[i] = minCost;
        }
        return dp[n-1];
    }
};