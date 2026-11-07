class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) {
            n = -n;
            x = 1 / x;
        }

        double res = 1;
        while (n >= 2) {
            int powerTwo = bit_floor((unsigned)n);
            n = n - powerTwo;
            double tmpRes = x;
            while (powerTwo >= 2) {
                tmpRes *= tmpRes;
                powerTwo /= 2;
            }
            res *= tmpRes;
        }

        if (n > 0) {
            res *= x;
        }

        return res;
    }
};
