class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int half = l + (r - l) / 2;
            if (target == nums[half]) {
                return half;
            }
            if (target > nums[half]) {
                l = half + 1;
            } else {
                r = half - 1;
            }
        }
        return -1;
        
    }
};
