class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }

        int total = nums1.size() + nums2.size();
        int half = total / 2;
        int left = 0, right = nums1.size();
        while (true) {
            int i = (left + right) / 2;
            int j = half - i;

            int part1Left = i > 0 ? nums1[i - 1] : INT_MIN;
            int part1Right = i < nums1.size() ? nums1[i] : INT_MAX;
            int part2Left = j > 0 ? nums2[j - 1] : INT_MIN;
            int part2Right = j < nums2.size() ? nums2[j] : INT_MAX;

            if (part1Left <= part2Right && part2Left <= part1Right) {
                if (total % 2 == 0) {
                    return (max(part1Left, part2Left) + min(part1Right, part2Right)) / 2.0; 
                } else {
                    return min(part1Right, part2Right);
                }
            } else if (part1Left > part2Right) {
                right = i - 1;
            } else {
                left = i + 1;
            }
        }
        return 0;
    }
};
