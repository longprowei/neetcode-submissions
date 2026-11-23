class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int total = 0;
        int startIndex = -1;
        for (int i = 0; i < n; i++) {
            total += gas[i];
            total -= cost[i];

            if (startIndex == -1 && gas[i] >= cost[i]) {
                startIndex = i;
            }
        }

        if (total < 0) {
            return -1;
        }

        int tank = 0;
        int i = startIndex;
        int cnt = 0;
        while (cnt != n) {
            tank += gas[i];
            tank -= cost[i];
            cnt++;
            if (tank < 0) {
                startIndex = (i + 1) % n;
                tank = 0;
                cnt = 0;
            }
            i = (i + 1) % n;
        }

        return startIndex;
    }
};
