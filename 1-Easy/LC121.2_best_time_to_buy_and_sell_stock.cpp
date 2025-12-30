// LeetCode 121 - Best Time to Buy and Sell Stock
// Topics: Array, Recursion, Greedy

class Solution {
    void rec(vector<int>& prices, int i, int &mini, int &maxProfit){
        int n = prices.size();
        if(i >= n)
            return;

        mini = min(mini, prices[i]);
        maxProfit = max(maxProfit, prices[i] - mini);

        rec(prices, i + 1, mini, maxProfit);
    }

public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int maxProfit = 0;
        rec(prices, 0, mini, maxProfit);
        return maxProfit; 
    }
};
