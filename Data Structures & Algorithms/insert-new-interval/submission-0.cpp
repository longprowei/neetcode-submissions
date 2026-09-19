class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        bool inserted = false;
        for (int i = 0; i < intervals.size(); i++) {
            auto interval = intervals[i];
            int start = interval[0];
            int end = interval[1];
            int newStart = newInterval[0];
            int newEnd = newInterval[1];
            if (!inserted && newStart <= end) {
                if (newEnd < start) {
                    res.push_back(newInterval);
                    res.push_back(interval);
                    inserted = true;
                    continue;
                }
                newInterval[0] = min(newStart, start);
                newInterval[1] = max(newEnd, end);
            } else {
                res.push_back(interval);
            }
        }
        if (!inserted) {
            res.push_back(newInterval);
        }
        
        return res;
    }
};
