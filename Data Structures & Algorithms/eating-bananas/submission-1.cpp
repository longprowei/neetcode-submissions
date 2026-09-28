class Solution {
private:
    bool canFinish(vector<int>& piles, int h, int k) {
        long long totalHours = 0;
        for (auto pile : piles) {
            totalHours += pile / k;
            totalHours += (pile % k == 0) ? 0 : 1;
        }

        return totalHours <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 1e9; // r is maximum possible value in the pile
        int minK = 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (canFinish(piles, h, mid)) {
                minK = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return minK;
    }
};
