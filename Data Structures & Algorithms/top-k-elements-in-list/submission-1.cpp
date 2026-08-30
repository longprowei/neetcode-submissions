class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for (int n : nums) {
            freqMap[n]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);
        for (auto [n, cnt] : freqMap) {
            buckets[cnt].push_back(n);
        }

        vector<int> topK;
        for (int i = nums.size(); i > 0; i--) {
            vector<int> &bucket = buckets[i];
            if (bucket.size() > 0) {
                for (int j = 0; j < bucket.size() && k > 0; j++, k--) {
                    topK.push_back(bucket[j]);
                }
                if (k == 0) break;
            }
        }
        
        return topK;
    }
};
