class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> sMap;
        unordered_map<char, int> tMap;
        for (char c : s) {
            sMap[c]++;
        }

        for (char c : t) {
            tMap[c]++;
        }

        if (sMap.size() != tMap.size()) {
            return false;
        }

        for (auto [c, cnt] : sMap) {
            if (!tMap.contains(c)) return false; 
            if (tMap[c] != cnt) {
                return false;
            }
        }

        return true;
    }
};
