// 121. Best Time to Buy and Sell Stock

// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

// if you are selling a stock on ith day,you need to buy on the minimum price from the 1 to i-1th day .
// TC = O(n)
// SC = O(1)
 class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int maxi = 0;
        for(int i=1;i<prices.size();i++){
            int cost = prices[i] - mini;
            maxi = max(maxi,cost);
            mini = min(mini , prices[i]);
        }
        return maxi;
    }
};