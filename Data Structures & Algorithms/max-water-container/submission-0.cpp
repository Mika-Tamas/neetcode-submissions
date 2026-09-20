class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() -1 ;

        int max_v = 0;

        while (r > l) {
            max_v = max(max_v,(r-l)* min(heights[r], heights[l]));

            if (heights[r] < heights[l]) {
                r--;
            } else {
                l++;
            }
        }

        return max_v;
    }
};
