// Perfect Sum Problem GFG
// Given an array arr[] of non-negative integers and an integer sum, the task is to count all subsets of the given array with a sum equal to a given sum.

// Memoization
// TC = O(N*sum)
// SC = O(N) + O(N*sum)
class Solution{
    int mod = 1e9+7;
    int func(int ind,int sum,int arr[],vector<vector<int>>&dp){
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
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return func(n-1,sum,arr,dp)%mod;
	}
};