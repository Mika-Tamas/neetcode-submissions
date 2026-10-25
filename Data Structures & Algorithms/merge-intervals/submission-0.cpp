class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());

        vector<vector<int>> res;

        for (int i = 0; i < intervals.size(); i++) {
            while (intervals.size() - 1 > i && intervals[i][1] >= intervals[i+1][0]) {
                intervals[i+1] = {intervals[i][0],max(intervals[i][1],intervals[i+1][1])};
                i++;
            }
            res.push_back(intervals[i]);
        }

        return res;
    }
};
