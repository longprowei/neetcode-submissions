class Solution {
public:
    int reverse(int x) {
        bool isPositive = x >= 0;
        if (x < 0) {
            x = -x;
        }
        
        const int MOD = 1e9 + 7;
        int newX = 0;
        while (x != 0) {
            if (newX > INT_MAX / 10) {
                return 0;
            }
            newX *= 10;
            newX += x % 10;
            x /= 10;
        }

        return isPositive ? newX : -newX;
    }
};
