// 494. Target Sum - LeetCode

// You are given an integer array nums and an integer target.
// You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

// For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
// Return the number of different expressions that you can build, which evaluates to target.

// Converted This problem into dividing array into two subsets such that their difference is equal to target and return count of these subsets.


class Solution {

    int func(int ind,int sum,vector<int>&arr,vector<vector<int>>&dp){
        if(ind == 0){
            if(sum == 0 && arr[0] == 0) return 2;
            if(sum == 0 || sum == arr[0]) return 1;
            return 0;
        }
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        int pick = 0;
        if(arr[ind] <= sum){
            pick = func(ind-1,(sum-arr[ind]),arr,dp);
        }
        int notPick = func(ind-1,sum,arr,dp);
        return dp[ind][sum] = (pick+ notPick);
    }
	public:
	int perfectSum(vector<int>&arr, int n, int sum)
	{
        // Your code goes here
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return func(n-1,sum,arr,dp);
	}
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int totSum = 0;
        for(int i=0;i<n;i++) totSum+=arr[i];
        if(totSum-d < 0 or (totSum-d)%2 ) return false;
        return perfectSum(arr,n,(totSum-d)/2);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return countPartitions(n,target,nums);
    }
};
