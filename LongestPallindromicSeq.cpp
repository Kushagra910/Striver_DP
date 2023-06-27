// Longest Palindromic Subsequence 
// Given a String, find the longest palindromic subsequence.
// instead of thinking a new logic we have utilised the previous one which is LCS
// and obtained the Longet pallindromic Subsequence by using string A and reverse of A

class Solution{
    int lcs(int n1, int n2, string text1, string text2)
    {
        // your code here
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
    
  public:
    int longestPalinSubseq(string A) {
        //code here
        int n = A.size();
        string B = "";
        for(int i = n-1;i>=0;i--){
             B.push_back(A[i]);
        }
        return lcs(n,n,A,B);
    }
};