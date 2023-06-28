//1312. Minimum Insertion Steps to Make a String Palindrome 
//Given a string s. In one step you can insert any character at any index of the string.
// Return the minimum number of steps to make s palindrome.
// A Palindrome String is one that reads the same backward as well as forward.

// Logic is in keeping the longest pallindromic Subsequence intact and not matching part in 
// anywhere to make pallindrome ,so total number of insertions would be (n - LCS(s))


// TC = O(n*m) + O(n)
// SC = O(n*m) + O(n)
 int longestPallindromicSubsequence(string s1,string s2,int n,int m){
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i = 0;i<=n;i++) dp[i][0] = 0;
        for(int j=0;j<=m;j++) dp[0][j] = 0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
public:
    int minInsertions(string s) {
        int n = s.size();
        string r = "";
        for(int i=n-1;i>=0;i--){
            r.push_back(s[i]);
        }
        return n - longestPallindromicSubsequence(s,r,n,n);
    }