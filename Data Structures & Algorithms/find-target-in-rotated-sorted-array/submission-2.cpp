class Solution {
public:
    int search(vector<int>& nums, int target) {
        // find the minmal number position first
        int minPos = 0;
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] <= nums[hi]) {
                hi = mid;
            } else {
                lo = mid + 1;
                minPos = lo;
            }
        }

        if (minPos == 0) {
            // the array is sorted
            auto it = lower_bound(nums.begin(), nums.end(), target);
            if (it != nums.end() && *it == target) {
                return it - nums.begin();
            } else {
                return -1;
            }
        } else {
            auto it1 = lower_bound(nums.begin(), nums.begin() + minPos, target);
            if (it1 != nums.begin() + minPos && *it1 == target) {
                return it1 - nums.begin();
            } else {
                auto it2 = lower_bound(nums.begin() + minPos, nums.end(), target);
                if (it2 != nums.end() && *it2 == target) {
                    return it2 - nums.begin();
                } else {
                    return -1;
                }
            }
        }
    }
};
