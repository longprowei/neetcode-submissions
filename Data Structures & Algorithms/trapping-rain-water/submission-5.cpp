class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxLeft = height[left];
        int maxRight = height[right];
        int res = 0;

        while (left < right) {
            if (maxLeft < maxRight) {
                // the water trapped is only depands on the left
                left++;
                maxLeft = max(maxLeft, height[left]);
                res += maxLeft - height[left];
            } else {
                right--;
                maxRight = max(maxRight, height[right]);
                res += maxRight - height[right];
            }
        }
        return res;
    }
};
