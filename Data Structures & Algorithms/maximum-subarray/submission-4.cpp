class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() < 1) return 0;

        int sum_cur = nums[0];
        int max_sf = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (sum_cur < 0) {
                sum_cur = 0;
            }
            sum_cur += nums[i];
            max_sf = max(max_sf,sum_cur);
                
        }

        return max_sf;
    }
};
