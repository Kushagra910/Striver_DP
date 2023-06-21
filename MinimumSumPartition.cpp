//Minimum sum partition GFG
//Given an array arr of size n containing non-negative integers,the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum
//  and find the minimum difference

//Created Logic from Sub setSum equal to target
// and taken tabulation code of DP-14 lecture
// which tells for n-1th row weahter for entire targetSum (o to targetSum) wether it is possible or not

//TC = O(n*sum) + O(totSum/2) + O(n);
//SC = O(n*sum)

class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int totSum = 0;
        for(int i=0;i<n;i++) totSum += arr[i];
        int sum = totSum;
        vector<vector<int>>dp(n,vector<int>(sum+1,0));
        for(int ind = 0;ind<n;ind++){
            dp[ind][0] = true;
        }
        if(arr[0]<=sum){
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
        int mini = 1e9;
        for(int s1=0;s1<=totSum/2;s1++){
            if(dp[n-1][s1] == true){
                mini = min(mini,abs(s1 - (totSum-s1)));
            }
        }
        return mini;
	} 
};


