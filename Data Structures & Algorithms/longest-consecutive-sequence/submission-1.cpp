class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int max_seq = 1;
        unordered_map<int,int> seen;
        for (int i = 0; i < nums.size(); i++) {
            int cur = nums[i];
            if (seen.find(cur) != seen.end()) {
                continue;
            }
            seen[nums[i]] = 1;

            while (seen.find(--cur) != seen.end()) {
                seen[nums[i]]++;
                seen[cur]++;
                max_seq = max({max_seq,seen[nums[i]],seen[cur]});
            }
            cur = nums[i];
            while (seen.find(++cur) != seen.end()) {
                seen[nums[i]]++;
                seen[cur]++;
                max_seq = max({max_seq,seen[nums[i]],seen[cur]});
            }
        }
        return max_seq;
    }
};
