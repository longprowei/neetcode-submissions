class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int _k;
public:
    KthLargest(int k, vector<int>& nums) {
        _k = k;
        for (auto num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > _k) {
            minHeap.pop();
        }

        return minHeap.top();
    }
};
