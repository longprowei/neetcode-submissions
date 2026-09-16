class Solution {
public:
    int climbStairs(int n) {
        vector<int> ways(3);
        ways[0] = 1;
        for (int i = 1; i <= n; i++) {
            ways[i % 3] = ways[(i - 1) % 3];
            if (i - 2 >= 0) {
                ways[i % 3] += ways[(i - 2) % 3];
            }
        }
        return ways[n % 3];
    }
};
