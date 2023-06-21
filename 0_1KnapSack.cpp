// 

// Recurrence
// TC = O(2*n)
// SC = O(n)

class Solution
{
    int func(int ind,int bagW,int wt[],int val[]){
        if(ind == 0){
            if(wt[0]<=bagW) return val[ind];
            else return 0;
        }
        int notTake = func(ind-1,bagW,wt,val);
        int take = INT_MIN;
        if(wt[ind]<=bagW){
            take = val[ind] + func(ind-1,bagW-wt[ind],wt,val);
        }
        return max(take,notTake);
    }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       return func(n-1,W,wt,val);
    }
};

//Memoization 
// TC = O(n*W);
// SC = O(n*W) + O(n)

class Solution
{
    int func(int ind,int bagW,int wt[],int val[],vector<vector<int>>&dp){
        if(ind == 0){
            if(wt[0]<=bagW) return val[ind];
            else return 0;
        }
        if(dp[ind][bagW] != -1) return dp[ind][bagW];
        int notTake = func(ind-1,bagW,wt,val,dp);
        int take = INT_MIN;
        if(wt[ind]<=bagW){
            take = val[ind] + func(ind-1,bagW-wt[ind],wt,val,dp);
        }
        return dp[ind][bagW] = max(take,notTake);
    }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n,vector<int>(W+1,-1));
       return func(n-1,W,wt,val,dp);
    }
};


// Tabulation Bottom Up
// TC = O(n*W)
// SC = O(n*W)

   int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>>dp(n,vector<int>(W+1,0));
       for(int i=wt[0];i<=W;i++) dp[0][i] = val[0];
       
       for(int ind = 1;ind<n;ind++){
           for(int bagW = 0;bagW<=W;bagW++){
                int notTake = dp[ind-1][bagW];
                int take = INT_MIN;
                if(wt[ind]<=bagW){
                    take = val[ind] + dp[ind-1][bagW-wt[ind]];
                }
                dp[ind][bagW] = max(take,notTake);
           }
       }
       return dp[n-1][W];
    }

    // SpaceOptimization
   // TC = O(n*W)
   // SC = O(W) 

       int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<int>prev(W+1,0),curr(W+1,0);
       for(int i=wt[0];i<=W;i++) prev[i] = val[0];
       
       for(int ind = 1;ind<n;ind++){
           for(int bagW = 0;bagW<=W;bagW++){
                int notTake = prev[bagW];
                int take = INT_MIN;
                if(wt[ind]<=bagW){
                    take = val[ind] + prev[bagW-wt[ind]];
                }
               curr[bagW] = max(take,notTake);
           }
           prev = curr;
       }
       return prev[W];
    }