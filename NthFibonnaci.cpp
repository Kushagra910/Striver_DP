#include<bits/stdc++.h>
using namespace std;

// Recursive Code 
// TC = exponential
// SC = O(N) recursion stack Space


int recursive(int n){
  if(n<=1) return n;
  return recursive(n-1) + recursive(n-2);
}

//TC = O(n)
// SC = O(n) + O(n) 
int memoization(int n,vector<int>&dp){
  if(n<=1) return n;
  if(dp[n]!=-1) return dp[n];
  return dp[n] = memoization(n-1,dp) + memoization(n-2,dp);
}

//Tabulation 
// TC = O(n)
// SC = O(n) for array
int tab(int n){
  int dp[n+1];
  dp[0] = 0;
  dp[1] = 1;
  for(int i=2;i<=n;i++){
    dp[i] = dp[i-1] + dp[i-2];
  }
  return dp[n];
}


int main(){
  int n;
  cin >> n;
  // cout << recursive(n) << endl;
  // vector<int>dp(n+1,-1);
  // cout << memoization(n,dp) << endl;

  // cout << tab(n) <<endl;


  // Space Optimization
  // TC = O(n)
  // SC = O(1)

  int prev2 = 0;
  int prev = 1;
  for(int i=2;i<=n;i++){
    int curr = prev + prev2;
    prev2 = prev;
    prev = curr;
  }

  cout << prev << endl;
  return 0;
}