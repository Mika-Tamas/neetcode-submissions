/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {

        int n = intervals.size();
        
        vector<int> starts;
        vector<int> ends;

        for (const auto& interval : intervals) {
            starts.push_back(interval.start);
            ends.push_back(interval.end);
        }

        sort(starts.begin(),starts.end());
        sort(ends.begin(),ends.end());

        int s = 0;
        int e = 0;
        int c = 0;
        int res = 0;

        while (s < n && e < n) {
            if (ends[e] > starts[s]) {
                s++;
                c++;
            } else {
                e++;
                c--;
            }
            res = max(res,c);
        }

        return res;
    }
};
