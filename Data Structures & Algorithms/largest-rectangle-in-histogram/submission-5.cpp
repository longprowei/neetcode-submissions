class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftIndex(n);
        vector<int> rightIndex(n);
        stack<int> stackLeft;
        stack<int> stackRight;
        
        stackLeft.push(-1);
        for (int i = 0; i < n; i++) {
            while (stackLeft.top() != -1 && heights[stackLeft.top()] >= heights[i]) {
                stackLeft.pop();
            }
            leftIndex[i] = stackLeft.top();
            if (i < n - 1 && heights[i] < heights[i + 1]) {
                stackLeft.push(i);
            }
            //cerr << "leftIndex " << i << "=" << leftIndex[i] << endl;
        }

        stackRight.push(n);
        for (int i = n - 1; i >= 0; i--) {
            while (stackRight.top() != n && heights[stackRight.top()] >= heights[i]) {
                stackRight.pop();
            }
            rightIndex[i] = stackRight.top();
            if (i > 0 && heights[i] < heights[i - 1]) {
                stackRight.push(i);
            }
            //cerr << "rightIndex " << i << "=" << rightIndex[i] << endl;
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, (rightIndex[i] - leftIndex[i] - 1) * heights[i]);
        }
        
        return res;
    }
};
