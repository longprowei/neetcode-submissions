class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }

        if (groupSize == 1) {
            return true;
        }

        int n = hand.size();
        unordered_map<int,int> freqMap;
        for (const auto & card: hand) {
            freqMap[card]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq(freqMap.begin(), freqMap.end());

        int groups = n / groupSize;
        for (int i = 0; i < groups; i++) {
            int j = 0;
            vector<pair<int,int>> temp;
            
            while (j < groupSize) {
                auto [card, cnt] = pq.top();
                pq.pop();
                cnt--;
                if (cnt != 0) {
                    temp.push_back({card, cnt});
                }
                
                if (j != groupSize - 1 && card != pq.top().first - 1) {
                    return false;
                }
                j++;
            }

            // push the temp pairs to the heap again
            for (const auto & p : temp) {
                pq.push(p);
            }
        }

        return true;
    }
};
