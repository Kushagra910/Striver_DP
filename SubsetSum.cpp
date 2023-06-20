// Subset Sum Problem GFG
// Given an array of non-negative integers, and a value sum,
//  determine if there is a subset of the given set with sum equal to given sum. 

// Try All possible Ways  --> Recursion
// TC  = O(2*n) or Exponential
// SC = O(n)

class Solution{   
    int func(int ind,int target,vector<int>&arr){
        if(target == 0) return true;
        if(ind == 0) return (arr[ind] == target);
        int take = false;
        if(arr[ind]<=target) take = func(ind-1,target-arr[ind],arr);
        int notTake = func(ind-1,target,arr);
        return take or notTake;
    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        return func(n-1,sum,arr);
    }
};

// Memoization
// TC = O(n*target)
// SC = O(n) + O(n*target)

class Solution{   
    int func(int ind,int target,vector<int>&arr,vector<vector<int>>&dp){
        if(target == 0) return true;
        if(ind == 0) return (arr[ind] == target);
        if(dp[ind][target]!=-1) return dp[ind][target];
        int take = false;
        if(arr[ind]<=target) take = func(ind-1,target-arr[ind],arr,dp);
        int notTake = func(ind-1,target,arr,dp);
        return dp[ind][target] = take or notTake;
    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(1e5+1,-1));
        return func(n-1,sum,arr,dp);
    }
};

// Tabulation 
// TC = O(n*target)
// SC = O(n*target)

    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,0));
        for(int ind = 0;ind<n;ind++){
            dp[ind][0] = true;
        }
        if(arr[0]<=sum){   // if arr[0] > sum then it becomes out of bounds and give a runtime error
             dp[0][arr[0]] = true;
        }
        for(int i=1;i<n;i++){
            for(int tar = 1;tar<=sum;tar++){
                int take = false;
                if(arr[i]<=tar) take = dp[i-1][tar-arr[i]];
                int notTake = dp[i-1][tar];
                dp[i][tar] = take or notTake;
            }
        }
        return dp[n-1][sum];
    }


