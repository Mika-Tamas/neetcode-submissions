class Solution {
public:
    int climbStairs(int n) {

        int fst = 1;
        int scd = 2;

        for (int i = 2; i < n; i++) {
            int tmp = scd;
            scd = scd + fst;
            fst = tmp;
        }

        return (n < 2) ? fst : scd;

    }
};
