//115. Distinct Subsequences

//Given two strings s and t, return the number of distinct 
// subsequences of s which equals t.
// The test cases are generated so that the answer fits on a 32-bit signed integer.

// String Matching Concept 
// You have to follow different methods of compairing which gives hint of trying all possible ways
// which implies Recursion is applied 

// Recursion
// TC = 2*n X 2*m
// SC = O(n+m)


// Memoized
// TC = O(n*m)
// SC = O(n*m) + O(n+m)

class Solution {
    int func(int i,int j,string s,string t,vector<vector<int>>&dp){
        if(j<0) return 1;
        if(i<0) return 0; 
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]){
            return dp[i][j] = func(i-1,j-1,s,t,dp)+func(i-1,j,s,t,dp);
        }
        else{
            return dp[i][j] =func(i-1,j,s,t,dp);
        }
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return func(n-1,m-1,s,t,dp);
    }
};

// Tabulation 
// TC = O(n*m) 
// SC = O(n*m)

//Here use Double datatype because int and long long is giving overflow error

class Solution {
    int func(int i,int j,string s,string t,vector<vector<int>>&dp){
        if(j<0) return 1;
        if(i<0) return 0; 
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]){
            return dp[i][j] = func(i-1,j-1,s,t,dp)+func(i-1,j,s,t,dp);
        }
        else{
            return dp[i][j] =func(i-1,j,s,t,dp);
        }
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<double>>dp(n+1,vector<double>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0] = 1; 
        }
        for(int j=1;j<=m;j++){
            dp[0][j] = 0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return (int)dp[n][m];
    }
};