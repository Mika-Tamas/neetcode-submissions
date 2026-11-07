class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;

        for (int i = 0; i < s.size(); i++) {
            res++;

            int l = i;
            int r = i+1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                l--; r++; res++;
            }
            l = i-1;
            r = i+1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                l--; r++; res++;
            }
        }

        return res;
    }
};
