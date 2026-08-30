class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for (int n : nums) {
            freqMap[n]++;
        }

        priority_queue<pair<int, int>> topFreq;
        for (auto [n, cnt] : freqMap) {
            topFreq.emplace(cnt, n);
        }

        vector<int> topK;
        for (int i = 0; i < k; i++) {
            auto [cnt, n] = topFreq.top();
            topK.push_back(n);
            topFreq.pop();
        }
        return topK;
    }
};
