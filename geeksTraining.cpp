// Geek's Training /  Ninja Training

// Geek is going for n days training program, he can perform any one of these three activities Running, Fighting, and Learning Practice. 
// Each activity has some point on each day. as Geek wants to improve all his skills, he can't do the same activity on two consecutive days,
//  help Geek to maximize his merit points as we were given a 2D array of n*3 points corresponding to each day and activity.

// Recursive
// TC = exponential
// SC = O(N) rss

class Solution {
  int func(int day,int last,vector<vector<int>>&points){
      if(day == 0){
          int maxi = 0;
          for(int task=0;task<3;task++){
              if(task!=last){
                  maxi = max(maxi,points[0][task]);
              }
          }
          return maxi;
      }
      int maxi = 0;
      for(int task = 0;task<3;task++){
          if(task!=last){
              int point = points[day][task] + func(day-1,task,points);
              maxi = max(maxi,point);
          }
      }
      return maxi;
  }
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        return func(n-1,3,points);
    }
};

// Memoization
// TC = O(n*4*3)
// SC = O(n) + O(n*4)

class Solution {
  int func(int day,int last,vector<vector<int>>&points,vector<vector<int>>&dp){
      if(day == 0){
          int maxi = 0;
          for(int task=0;task<3;task++){
              if(task!=last){
                  maxi = max(maxi,points[0][task]);
              }
          }
          return maxi;
      }
      if(dp[day][last] != - 1) return dp[day][last];
      int maxi = 0;
      for(int task = 0;task<3;task++){
          if(task!=last){
              int point = points[day][task] + func(day-1,task,points,dp);
              maxi = max(maxi,point);
          }
      }
      return dp[day][last] = maxi;
  }
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return func(n-1,3,points,dp);
    }
};