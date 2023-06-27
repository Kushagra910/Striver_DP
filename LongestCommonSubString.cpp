// Longest Common Substring GFG

// Given two strings. The task is to find the length of the longest common substring.
// From DP table / tabulation code of longest common subsequence we just have removed
// the dividing part of non-match stored 0 in it ,rest all is same 

// TC = O(n1*n2) + O(n1 + n2)
// SC = O(n1*n2) 
    int longestCommonSubstr (string text1, string text2, int n, int m)
    {
        // your code here
            int n1 = text1.length();
		    int n2 = text2.length();
		    vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
            for(int i=0;i<=n1;i++) dp[i][0] = 0;
            for(int j=0;j<=n2;j++) dp[0][j] = 0;
    
            for(int i=1;i<=n1;i++){
                for(int j=1;j<=n2;j++){
                    if(text1[i -1 ] == text2[j - 1]){
                         dp[i][j]  = 1 + dp[i-1][j-1];
                    }
                   else dp[i][j] = 0;
                }
            }
            int ans = 0;
            for(int i=0;i<=n1;i++){
                for(int j=0;j<=n2;j++){
                    ans = max(ans,dp[i][j]);
                }
            }
            return ans;
    }