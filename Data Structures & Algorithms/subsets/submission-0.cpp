class Solution {
    void backtrack(vector<vector<int>>& res, vector<int>& nums, vector<int>& cur, int i) {
        if (i >= nums.size()) {
            res.push_back(cur);
            return;
        }

        cur.push_back(nums[i]);
        backtrack(res, nums, cur, i + 1);
        cur.pop_back();
        backtrack(res, nums, cur, i + 1);

        return;
    }

   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        backtrack(res, nums, cur, 0);
        return res;
    }
};
