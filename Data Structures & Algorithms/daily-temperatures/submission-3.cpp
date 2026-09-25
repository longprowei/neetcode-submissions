class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> indexStack;
        
        for (int i = 0; i < n; i++) {
            while (!indexStack.empty() && temperatures[i] > temperatures[indexStack.top()]) {
                int j = indexStack.top();
                res[j] = i - j;
                indexStack.pop();
            }
            indexStack.push(i);
        }

        return res;
    }
};
