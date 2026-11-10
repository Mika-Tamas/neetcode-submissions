class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> prefix(height.size());
        vector<int> suffix(height.size());

        int s = INT_MIN;
        for (int i = 0; i < prefix.size(); i++) {
            s = max(s,height[i]);
            prefix[i] = s;
        }

        s = INT_MIN;
        for (int i = suffix.size()-1; i >= 0; i--) {
            s = max(s,height[i]);
            suffix[i] = s;
        }
        int res = 0;
        for (int i = 0; i < height.size(); i++) {
            res += min(prefix[i], suffix[i]) - height[i];
        }

        return res;
    }
};
