using DIST = pair<int, int>; // dist's square, index of points

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<DIST> maxHeap;

        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            maxHeap.emplace(x * x + y * y, i);
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        vector<vector<int>> res;
        while (!maxHeap.empty()) {
            auto [dist, index] = maxHeap.top();
            res.push_back(points[index]);
            maxHeap.pop();
        }

        return res;
    }
};
