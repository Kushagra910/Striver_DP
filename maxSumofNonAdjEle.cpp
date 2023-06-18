// Max Sum without Adjacents GFG

// Given an array Arr of size N containing positive integers. Find the maximum sum of a subsequence such that no two numbers in the sequence should be adjacent in the array.
// Try all possible ways but with constraint that you cannot take adjacent element
// func function returns maxSum which i can get from picking up a subsequence with no Adjacent element on moving from 0 to ind.

// MemoIzed
// TC = O(n)
// SC = O(n) + O(n)
class Solution{
    int func(int ind,int *arr,vector<int>&dp){
        if(ind == 0) return arr[ind];
        if(ind < 0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int pick = arr[ind] + func(ind-2,arr,dp);
        int notPick = func(ind-1,arr,dp);
        return dp[ind] =  max(pick,notPick);
    }
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int>dp(n,-1);
	    return func(n-1,arr,dp);
	}
};


// Tabulation 
// TC = O(n)
// SC = O(n)

class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int>dp(n);
	    dp[0] = arr[0];
	    for(int i=1;i<n;i++){              // edge case handling if(i>1) dp[i-2];
	        int pick = arr[i];
          if(i>1){
            pick+=dp[i-2];
          }
	        int notPick = dp[i-1];
	        dp[i] = max(pick,notPick);
	    }
	    return dp[n-1];
	}
};