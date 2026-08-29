class Solution {
private:
    const int LETTERS_NUM = 26;
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> freqMap;

        for (int i = 0; i < strs.size(); i++) {
            vector<int> freqTable(LETTERS_NUM);
            for (char c : strs[i]) {
                freqTable[c - 'a']++;
            }
            
            string freqStr = to_string(freqTable[0]);
            for (int j = 1; j < freqTable.size(); j++) {
                freqStr += "," + to_string(freqTable[j]);
            }
            freqMap[freqStr].push_back(strs[i]);
        }

        vector<vector<string>> result;
        for (auto [key, group] : freqMap) {
            result.push_back(group);
        }
        return result;
    }
};
