class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int n = intervals.size();
        int res = 0;
        int prevStart = intervals[n - 1][0];
        for (int i = n - 2; i >= 0; i--) {
            int currEnd = intervals[i][1];
            //cerr << "currEnd:" << currEnd << " prevStart=" << prevStart << endl;
            if (currEnd > prevStart) {
                res++;
            } else {
                prevStart = intervals[i][0];
            }
        }

        return res;
    }
};
