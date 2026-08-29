class Solution {
private:
    const int LETTERS = 26;
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        vector<int> freqTable(LETTERS, 0);
        for (int i = 0; i < s.length(); i++) {
            freqTable[s[i] - 'a']++;
            freqTable[t[i] - 'a']--;
        }

        for (int c : freqTable) {
            if (c != 0) {
                return false;
            }
        }

        return true;
    }
};
