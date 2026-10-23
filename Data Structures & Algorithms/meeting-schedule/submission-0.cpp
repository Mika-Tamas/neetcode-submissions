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
    bool canAttendMeetings(vector<Interval>& intervals) {
        
        sort(intervals.begin(),intervals.end(), [](auto& x, auto& y) { return x.start < y.start; });
        
        int cur_end = 0;
        for (auto iv : intervals) {
            if (iv.start < cur_end || iv.end <= cur_end) {
                return false;
            }
            cur_end = iv.end;
        }
        return true;
    }
};
