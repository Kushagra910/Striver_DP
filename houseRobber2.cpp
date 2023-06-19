//House Robber II
// professional robber plans on robbing houses arranged in a circular way but cannot robb two consecutive
// houses because of security system , given arr representing the amount of money of each house , your task 
// is to return maximum money can be robbed 

// Same Approach ans maxSumofNonAdjacentElemnet but with Slight moderation ,we will apply the same logic on two arrays
// first one not having last element and second one not having first element and take max of them.

//TC = O(n)
//SC = O(n)
#include<bits/stdc++.h>
long long int ans(vector<int> &nums){
    // Write your code here.
    long long int n=nums.size();
    long long int prev1=nums[0];
    long long int prev2=0;
    for(int i=1;i<n;i++){
        long long int pick=nums[i];
        if(i>1){
            pick+=prev2;
        }
       long long int notpick=0+prev1;
       long long  int curr=max(pick,notpick);
        prev2=prev1;
        prev1=curr;
       }
    return prev1;
}
long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    vector<int>t1,t2;
    long long int n=valueInHouse.size();
    if(n==1) return valueInHouse[0];
    for(long long int i=0;i<n;i++){
        if(i!=0) t1.push_back(valueInHouse[i]);
        if(i!=n-1) t2.push_back(valueInHouse[i]);
    } 
    return max(ans(t1),ans(t2));
}

