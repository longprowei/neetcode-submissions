class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1);
        for (int i = 0; i <= n; i++) {
            int countOnes = 0;
            int num = i;
            while (num) {
                num &= num - 1;
                countOnes++;
            }
            res[i] = countOnes;
        }
        return res;
    }
};
