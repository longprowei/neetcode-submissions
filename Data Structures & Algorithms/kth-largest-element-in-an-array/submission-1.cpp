// average O(n) but worse is O(n^2)
class Solution {
private:
    int quickSelect(vector<int>& nums, int k, int l, int r) {
        int pivot = nums[r];
        int p = l;
        
        for (int i = l; i < r; i++) {
            if (nums[i] <= pivot) {
                swap(nums[i], nums[p]);
                p++;
            }
        }
        swap(nums[p], nums[r]);

        if (p < k) {
            return quickSelect(nums, k, p + 1, r);
        } else if (p > k) {
            return quickSelect(nums, k, l, p - 1);
        } else {
            return nums[p];
        }
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        return quickSelect(nums, k, 0, nums.size() - 1);
    }
};
