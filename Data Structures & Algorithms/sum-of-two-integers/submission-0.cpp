class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0;
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int digit_a = a >> i & 1;
            int digit_b = b >> i & 1;

            int digit_cur = digit_a ^ digit_b ^ carry;
            carry = (digit_a + digit_b + carry) >= 2 ? 1 : 0;
            if (digit_cur) {
                res |= (1 << i);
            }
        }

        if (res > 0x7FFFFFFF) {
            res = ~(res ^ 0xFFFFFFFF);
        }

        return res;
    }
};
