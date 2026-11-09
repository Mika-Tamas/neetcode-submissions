class Solution {
    int helper(vector<int>& nums) {

        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];

        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        }

        return dp.back();
    }
public:
    int rob(vector<int>& nums) {

        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];

        std::vector<int> skip_first(nums.begin() + 1, nums.end());
        std::vector<int> skip_last(nums.begin(), nums.end() - 1);

        return max(helper(skip_first),helper(skip_last));
    }
};
