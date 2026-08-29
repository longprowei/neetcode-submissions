class Solution {
private:
    const int LETTERS_NUM = 26;
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<int>> freqMap;

        for (int i = 0; i < strs.size(); i++) {
            vector<int> freqTable(LETTERS_NUM);
            for (char c : strs[i]) {
                freqTable[c - 'a']++;
            }
            
            freqMap[freqTable].push_back(i);
        }

        vector<vector<string>> result;
        for (auto [key, v] : freqMap) {
            vector<string> group;
            for (int i : v) {
                group.push_back(strs[i]);
            }
            result.push_back(group);
        }
        return result;
    }
};
