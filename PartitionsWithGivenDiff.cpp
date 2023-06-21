
// Partitions with Given Difference GFG
// Given an array arr, partition it into two subsets(possibly empty) such that their union is the original array. Let the sum of the element of these two subsets be S1 and S2. 
// Given a difference d, count the number of partitions in which S1 is greater than or equal to S2 and the difference S1 and S2 is equal to d. 
// since the answer may be large return it modulo 109 + 7.Given a difference d, count the number of partitions in which S1 is greater than or equal to S2 and the difference S1 and S2 is equal to d. since the answer may be large return it modulo 109 + 7.


class Solution {
    int mod = 1e9+7;
    int func(int ind,int sum,vector<int>&arr,vector<vector<int>>&dp){
        if(ind < 0) return sum == 0;
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        int pick = 0;
        if(arr[ind] <= sum){
            pick = func(ind-1,(sum-arr[ind])%mod,arr,dp)%mod;
        }
        int notPick = func(ind-1,sum%mod,arr,dp)%mod;
        return dp[ind][sum] = (pick%mod + notPick%mod)%mod;
    }
	public:
	int perfectSum(vector<int>&arr, int n, int sum)
	{
        // Your code goes here
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return func(n-1,sum,arr,dp)%mod;
	}
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int totSum = 0;
        for(int i=0;i<n;i++) totSum+=arr[i];
        if(totSum-d < 0 or (totSum-d)%2 ) return false;
        return perfectSum(arr,n,(totSum-d)/2);
    }
};