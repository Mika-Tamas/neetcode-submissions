class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = *max_element(piles.begin(),piles.end());
        int l = 1;
        int res = r;

        while (l <= r) {
            int k = (l + r) / 2;
            long long time = 0;
            for (int& pile : piles) time += ceil(static_cast<double>(pile) / k);
            if (time <= h) {
                res = k;
                r = k - 1;
            } else {
                l = k + 1;
            }
        }

        return res;

    }
};
