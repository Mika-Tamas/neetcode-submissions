class Solution {
    vector<vector<int>> sol;
    void backtrack(int i, vector<int>& nums, int target, vector<int>& cur, int total) {
        if (total == target) {
            sol.push_back(cur);
            return;
        }
        if (total + nums[i] > target) {
            return;
        }
        cur.push_back(nums[i]);
        backtrack(i,nums,target,cur,total + nums[i]);
        cur.pop_back();
        if (i+1 >= nums.size() || total + nums[i+1] > target) {
            return;
        }
        backtrack(i+1,nums,target,cur,total);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> cur;
        backtrack(0,nums,target,cur,0);

        return sol;
    }
};
