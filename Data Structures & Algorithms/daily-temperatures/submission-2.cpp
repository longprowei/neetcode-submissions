class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> indexStack;
        indexStack.push(0);
        
        for (int i = 1; i < n; i++) {
            while (!indexStack.empty() && temperatures[i] > temperatures[indexStack.top()]) {
                res[indexStack.top()] = i - indexStack.top();
                indexStack.pop();
            }
            indexStack.push(i);
        }

        return res;
    }
};
