class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1);
        
        for (int i = 1; i <= amount; i++) {
            int min_c = INT_MAX;
            for (const auto& coin : coins) {
                if (i - coin < 0 || dp[i-coin] == -1) continue;
                min_c = min(min_c,dp[i-coin]+1); 
            }
            if (min_c == INT_MAX) min_c = -1;

            dp[i] = min_c;
        }

        return dp[amount];
    }
};
