class Solution {

    int dfs(vector<int>& nums,vector<vector<int>>& dp, int cur, int prev) {
        if (cur == nums.size()) return 0;
        if (dp[cur][prev + 1] != -1) return dp[cur][prev + 1];

        int LIS = dfs(nums,dp,cur+1,prev);

        if (prev == -1 || nums[prev] < nums[cur]) {
            LIS = max(LIS,1 + dfs(nums,dp,cur+1,cur));
        }

        dp[cur][prev+1] = LIS;
        return LIS;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
        
        return dfs(nums,dp,0,-1);
    }
};
