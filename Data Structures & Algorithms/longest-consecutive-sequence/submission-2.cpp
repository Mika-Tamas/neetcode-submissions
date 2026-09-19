class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> seen;
        int max_seq = 0;

        for (int num : nums) {
            if (!seen[num]) {
                seen[num] = seen[num - 1] + seen[num + 1] + 1;
                seen[num - seen[num - 1]] = seen[num];
                seen[num + seen[num + 1]] = seen[num];
                max_seq = max(max_seq, seen[num]);
            }
        }
        return max_seq;
    }
};