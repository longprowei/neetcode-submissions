class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> posSpeed(n);
        for (int i = 0; i < n; i++) {
            posSpeed[i] = {position[i], speed[i]};
        }

        sort(posSpeed.begin(), posSpeed.end(), greater<pair<int,int>>());

        stack<double> timeStack;
        for (int i = 0; i < n; i++) {
            double currTime = (target - posSpeed[i].first) * 1.0 / posSpeed[i].second;
            if (timeStack.empty()) {
                timeStack.push(currTime);
                continue;
            }

            double fleetTime = timeStack.top();
            if (currTime > fleetTime) {
                timeStack.push(currTime);
            }
        }

        return timeStack.size();
    }
};
