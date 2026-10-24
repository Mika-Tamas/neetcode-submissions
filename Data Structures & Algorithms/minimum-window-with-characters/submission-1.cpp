class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";

        
        pair<int, int> res = {-1, -1};
        int resLen = INT_MAX;
        int start = 0;
        unordered_map<char,int> window_freq;
        unordered_map<char,int> t_freq;

        for (char c : t) {
            t_freq[c]++;
        }

        int have = 0, need = t_freq.size();

        for (int i = 0; i < s.size(); i++) {

            char c = s[i];
            window_freq[c]++;

            if (t_freq.count(c) && window_freq[c] == t_freq[c]) {
                have++;
            }


            while (have == need) {
                if (i - start + 1 < resLen) {
                    resLen = i - start + 1;
                    res = {start, i};
                }
                
                window_freq[s[start]]--;
                if (t_freq.count(s[start]) && window_freq[s[start]] < t_freq[s[start]]) {
                    have--;
                }
                start++;
            }
        }

        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};
