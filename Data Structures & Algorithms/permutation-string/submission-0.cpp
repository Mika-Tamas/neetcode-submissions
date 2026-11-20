class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.size(), len2 = s2.size();
        if (len1 > len2) return false;

        array<int, 26> freq_s1{};
        array<int, 26> freq_s2{};

        for (int i = 0; i < len1; i++) {
            freq_s1[s1[i] - 'a']++;
            freq_s2[s2[i] - 'a']++;
        }

        if (freq_s1 == freq_s2) return true;

        for (int i = len1; i < len2; i++) {
            freq_s2[s2[i] - 'a']++;
            freq_s2[s2[i - len1] - 'a']--;

            if (freq_s1 == freq_s2) return true;
        }

        return false;
    }
};