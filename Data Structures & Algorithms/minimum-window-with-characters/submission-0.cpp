class Solution {
public:
    string minWindow(string s, string t) {
        
        string res = "";
        int start = 0;
        unordered_map<char,int> window_freq;
        unordered_map<char,int> t_freq;

        for (char c : t) {
            t_freq[c]++;
        }

        for (int i = 0; i < s.size(); i++) {
            window_freq[s[i]]++;

            bool valid = true;
            for (const auto& [chr, count] : t_freq) {
                if (window_freq[chr] < count) {
                    valid = false; break;
                }
            }

            if (valid) {
                while (start < i) {
                    if (t_freq.find(s[start]) == t_freq.end() || window_freq[s[start]] > t_freq[s[start]]) {
                        window_freq[s[start++]]--;
                    } else {
                        break;
                    }
                }
                
                if (i-start + 1 < res.size() || res.size() == 0) {
                    res = s.substr(start, i-start + 1);
                }
                                 
            }
        }

        return res;
    }
};
