class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        int cur;
        while((cur = numbers[l] + numbers[r]) != target) {
            if (cur > target) {
                r--;
            }
            if (cur < target) {
                l++;
            }
        }
        return {l+1,r+1};
    }
};
