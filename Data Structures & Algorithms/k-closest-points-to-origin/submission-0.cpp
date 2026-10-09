using DIST = pair<int, int>; // dist's square, index of points

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<DIST, vector<DIST>, greater<DIST>> minHeap;

        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            minHeap.emplace(x * x + y * y, i);
        }

        vector<vector<int>> res;
        for (int i = 0; i < k; i++) {
            res.push_back(points[minHeap.top().second]);
            minHeap.pop();
        }

        return res;
    }
};
