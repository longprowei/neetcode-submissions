class Solution {
public:
    int getSum(int a, int b) {
        bool carry = false;
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int b1 = (a >> i) & 1;
            int b2 = (b >> i) & 1;

            if (b1 == 1 && b2 == 1 && carry) {
                res |= 1 << i;
                carry = true;
            } else if ((b1 == 1 && b2 == 1) || (carry && (b1 == 1 || b2 == 1))) {
                carry = true;
            } else if (b1 == 1 || b2 == 1 || carry) {
                res |= 1 << i;
                carry = false;
            } else {
                carry = false;
            }
        }

        return res;
    }
};
