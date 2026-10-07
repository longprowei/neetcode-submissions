class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> numSet;
        numSet.insert(n);

        while (n != 1) {
            int digitSum = 0;
            while (n != 0) {
                int digit = n % 10;
                digitSum += digit * digit;
                n /= 10;
            }
            if (numSet.contains(digitSum)) {
                return false;
            }
            numSet.insert(digitSum);
            n = digitSum;
        }

        return true;
    }
};
