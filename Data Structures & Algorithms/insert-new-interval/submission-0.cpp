class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.size() < 1) return {{newInterval}};

        auto it = lower_bound(
            intervals.begin(),
            intervals.end(),
            newInterval[0],
            [](const std::vector<int>& interval, int target) {
                return interval[0] < target;
            });

        
        intervals.insert(it, newInterval);

        vector<vector<int>> res;
        for (const auto& interval : intervals) {
            if (res.empty() || res.back()[1] < interval[0]) {
                res.push_back(interval);
            } else {
                res.back()[1] = max(res.back()[1], interval[1]);
            }
        }

        return res;
        

        return intervals;
    }
};
