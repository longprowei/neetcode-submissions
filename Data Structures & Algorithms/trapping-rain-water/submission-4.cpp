class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = 0;
        int res = 0;
        while (left < n && right < n) {
            // put left on the right position
            while (left < n - 1 && height[left] <= height[left + 1]) {
                left++;
            }

            // put right on the right position
            right = min(left + 2, n - 1);

            int maxHeight = height[right];
            int maxIndex = right;
            while (right < n - 1 && (height[right] <= height[right + 1] || height[right] < height[left])) {
                right++;
                if (height[right] > maxHeight) {
                    maxHeight = height[right];
                    maxIndex = right;
                }
            }
            if (maxHeight >= height[right] && maxIndex != right) {
                right = maxIndex;
            }

            int waterLevel = min(height[left], height[right]);
            left++;
            while (left < right) {
                res += (waterLevel - height[left] > 0) ? waterLevel - height[left] : 0;
                left++;
            }
        }

        return res;
    }
};
