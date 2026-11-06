class Solution {
public:
    int reverse(int x) {
        bool isPositive = x >= 0;
        
        int newX = 0;
        while (x != 0) {
            if (newX > INT_MAX / 10 || newX < INT_MIN / 10) {
                return 0;
            }
            newX *= 10;
            newX += x % 10;
            x /= 10;
        }

        return newX;
    }
};
