class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> freq;
        int l = 0;
        int r = 0;
        int max_len = 0;
        while(r < s.length()) {
            char chr = s[r];
            freq[chr]++;
            while (freq[chr] > 1) {
                freq[s[l]]--;
                l++;
            }
            max_len = max(max_len,r-l+1);
            r++;
        }
        return max_len;
    }
};
