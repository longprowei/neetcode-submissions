class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0)) {
            return -1;
        }

        int tank = 0;
        int startIndex = 0;
        for (int i = 0; i < gas.size(); i++) {
            tank += gas[i] - cost[i];
            if (tank < 0) {
                tank = 0;
                startIndex = i + 1;
            }
        }

        return startIndex;
    }
};
