class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        int target = k - 1;

        while (left <= right) {
            int pivotIndex = left + rand() % (right - left + 1);
            int pivot = nums[pivotIndex];

            int l = left, r = right, i = left;
            while (i <= r) {
                if (nums[i] < pivot) {
                    swap(nums[i], nums[r--]);
                } else if (nums[i] > pivot) {
                    swap(nums[i++], nums[l++]);
                } else {
                    i++;
                }
            }

            if (target < l) {
                right = l - 1;
            } else if (target > r) {
                left = r + 1;
            } else {
                return nums[l];
            }
        }
    }
};
