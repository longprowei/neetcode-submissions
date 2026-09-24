class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }

        unordered_map<char, int> s1Map;
        for (int i = 0; i < s1.size(); i++) {
            s1Map[s1[i]]++;
        }

        unordered_map<char, int> s2Map;
        int s2Count = 0;
        for (int i = 0; i < s2.size(); i++) {
            if (i >= s1.size()) {
                char ch = s2[i - s1.size()];
                if (s1Map.contains(ch)) {
                    s2Count--;
                    s2Map[ch]--;
                    if (s2Map[ch] == 0) {
                        s2Map.erase(ch);
                    }
                }
            }
            if (s1Map.contains(s2[i])) {
                s2Count++;
                s2Map[s2[i]]++;
            }

            if (s1.size() == s2Count && s1Map == s2Map) {
                return true;
            }
        }

        return false; 
    }
};
