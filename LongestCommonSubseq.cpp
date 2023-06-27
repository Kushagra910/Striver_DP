// 1143. Longest Common Subsequence
// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.
// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// recursive solution 
// TC = O(2*n X 2*m)
// SC = O(n+m)

class Solution {
    int func(int ind1,int ind2,string text1,string text2){
        if(ind1 < 0 || ind2 < 0) return 0;
        if(text1[ind1] == text2[ind2]){
            return 1 + func(ind1-1,ind2-1,text1,text2);
        }
        return max(func(ind1-1,ind2,text1,text2),func(ind1,ind2-1,text1,text2));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        return func(n1-1,n2-1,text1,text2);
    }
};


// memoization --> TLE
// TC = O(n*m)
// sc = O(n*m) + o(n+m)

class Solution {
    int func(int ind1,int ind2,string text1,string text2,vector<vector<int>>&dp){
        if(ind1 < 0 || ind2 < 0) return 0;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        if(text1[ind1] == text2[ind2]){
            return  dp[ind1][ind2]  = 1 + func(ind1-1,ind2-1,text1,text2,dp);
        }
        return dp[ind1][ind2] = max(func(ind1-1,ind2,text1,text2,dp),func(ind1,ind2-1,text1,text2,dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        return func(n1-1,n2-1,text1,text2,dp);
    }
};


// Tabulation  with Shifted base Case because ind<0 cannot be handled here
// TC = O(n*m)
// SC = O(n*m)

    int longestCommonSubsequence(string text1, string text2) {
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
               else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n1][n2];
    }
