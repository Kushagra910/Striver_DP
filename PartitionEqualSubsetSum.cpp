// Partition Equal Subset Sum - CODESTUDIO
// You are given an array 'ARR' of 'N' positive integers. 
// Your task is to find if we can partition the given array into two subsets such that the sum of elements in both subsets is equal.


// Using same Code of SubsetSum with Logic that thus there exist a subset which is equal to totalSum/2,
//if yes we can divide the array into two subsets with equal sum

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<bool>>dp(n,vector<bool>(k+1,0));
    for(int i=0;i<n;i++){
        dp[i][0]=true;
    }
    dp[0][arr[0]]=true;
    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=k;target++){
            bool nottake=dp[ind-1][target];
            bool take=false;
            if(target>=arr[ind]){
                take=dp[ind-1][target-arr[ind]];
            }
            dp[ind][target]=take | nottake;
        }
    }
    return dp[n-1][k];
}
bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
    int totalsum=0;
    for(int i=0;i<n;i++){
        totalsum+=arr[i];
    }
    int target=totalsum/2;
    if(totalsum%2) return false;
    return subsetSumToK(n,target,arr);
}