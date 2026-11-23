class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int tank = 0;
        int startIndex = 0;
        int i = 0;
        int cnt = 0;

        // find first index that can move the next at least
        while (i < n && gas[i] < cost[i]) {
            i++;
        }

        if (i >= n) {
            return -1;
        }
        
        startIndex = i;
        tank += gas[i];
        tank -= cost[i];
        i = (i + 1) % n;
 
        while(startIndex != i && cnt < 2 * n) {
            tank += gas[i];
            tank -= cost[i];
            while (tank < 0) {
                i = (i + 1) % n;
                startIndex = i;
                tank = 0;
                tank += gas[i];
                tank -= cost[i];
                cnt++;
            }
            i = (i + 1) % n;
            cnt++;
        } 
        
        return cnt >= 2 * n ? -1 : startIndex;
    }
};
