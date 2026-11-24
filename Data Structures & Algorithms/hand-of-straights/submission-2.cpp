class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }

        int n = hand.size();
        unordered_map<int,int> freqMap;
        for (const auto & card: hand) {
            freqMap[card]++;
        }

        priority_queue<int, vector<int>, greater<int>> pq;
        for (const auto & [card, cnt] : freqMap) {
            pq.push(card);
        }

        int groups = n / groupSize;
        for (int i = 0; i < groups; i++) {
            int start = pq.top();
            for (int j = start; j < start + groupSize; j++) {
                if (freqMap[j] == 0) {
                    return false;
                }
                freqMap[j]--;
                if (freqMap[j] == 0) {
                    if (j != pq.top()) {
                        return false;
                    }
                    pq.pop();
                }
            }
        }

        return true;
    }
};
