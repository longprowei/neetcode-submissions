/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b) {
            return a.start < b.start;
        });

        priority_queue<int, vector<int>, greater<int>> endTimeHeap;
        for (const auto& interval : intervals) {
            if (endTimeHeap.empty()) {
                endTimeHeap.push(interval.end);
                continue;
            }

            if (interval.start >= endTimeHeap.top()) {
                endTimeHeap.pop();
            }
            endTimeHeap.push(interval.end);
        }
        return endTimeHeap.size();
    }
};
