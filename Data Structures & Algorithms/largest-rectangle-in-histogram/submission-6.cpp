class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> indexStack;
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            while (!indexStack.empty() && (
                    i == n || heights[i] < heights[indexStack.top()])) {
                int height = heights[indexStack.top()];
                indexStack.pop();
                int width = indexStack.empty() ? i : i - indexStack.top() - 1;
                maxArea = max(maxArea, height * width);
            }

            indexStack.push(i);
        }
        return maxArea;
    }
};
