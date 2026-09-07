class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int firstNum = nums[0];
        if (firstNum <= nums[n - 1]) {
            // it is ascending order already
            return nums[0];
        }

        int minPos = 0;
        int lo = 1, hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            //cerr << "lo=" << lo << " hi=" << hi << " mid=" << mid << endl;
            if (firstNum <= nums[mid]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
                minPos = mid;
            }
        }

        return nums[minPos];
    }
};
