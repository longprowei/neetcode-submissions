class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> posSpeed(n);
        for (int i = 0; i < n; i++) {
            posSpeed[i].first = position[i];
            posSpeed[i].second = speed[i];
        }

        sort(posSpeed.begin(), posSpeed.end(), [](pair<int,int>& a, pair<int,int>& b){
            return a.first > b.first;
        });

        stack<int> indexStack;
        for (int i = 0; i < n; i++) {
            if (indexStack.empty()) {
                indexStack.push(i);
                continue;
            }

            double currTime = (target - posSpeed[i].first) * 1.0 / posSpeed[i].second;
            int index = indexStack.top();
            double fleetTime = (target - posSpeed[index].first) * 1.0 / posSpeed[index].second;
            if (currTime > fleetTime) {
                indexStack.push(i);
            }
        }

        return indexStack.size();
    }
};
