class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (!nums.size()) return 0;

        int res = nums[0];
        int min_v = 1; int max_v = 1;

        for (int i = 0; i < nums.size(); i++) {
            int tmp_max = max_v * nums[i];
            max_v = max(min_v * nums[i],max(nums[i], tmp_max));
            min_v = min(tmp_max,min(nums[i], min_v * nums[i]));

            res = max(max_v,res);
        }

        return res;
    }
};
