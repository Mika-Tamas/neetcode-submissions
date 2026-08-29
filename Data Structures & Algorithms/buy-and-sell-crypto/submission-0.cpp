class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (min > prices[i]) {
                min = prices[i];
            }
            int cur_profit = prices[i] - min;
            if (cur_profit > profit) {
                profit = cur_profit;
            }
        }
        return profit;
    }
};
