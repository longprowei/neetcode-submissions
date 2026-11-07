class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }

        if (x == 1) {
            return x;
        }

        long long power = abs(n);
        double res = 1;
        while (power) {
            if (power & 1) {
                res *= x;
            }
            power >>= 1;
            x *= x;
        }

        return n > 0 ? res : 1 / res;
    }
};
