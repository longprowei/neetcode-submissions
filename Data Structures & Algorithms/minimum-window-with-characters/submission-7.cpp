class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tFreq;
        int needChars = 0;
        for (char c : t) {
            tFreq[c]++;
            needChars++;
        }

        string minSubStr;
        int minL = -1;
        int minLen = s.size() + 1;
        unordered_map<char, int> sFreq;
        int left = 0;
        int havingCount = 0;
        for (int i = 0; i < s.size(); i++) {
            sFreq[s[i]]++;
            
            if (tFreq.contains(s[i]) && sFreq[s[i]] <= tFreq[s[i]]) {
                havingCount++;
            }

            while (havingCount == needChars) {
                if (i - left + 1 < minLen) {
                    minL = left;
                    minLen = i - left + 1;
                }
                sFreq[s[left]]--;
                if (tFreq.contains(s[left]) && sFreq[s[left]] < tFreq[s[left]]) {
                    havingCount--;
                }
                left++;
            }
        }

        if (minL != -1) {
            minSubStr = s.substr(minL, minLen);
        }

        return minSubStr;
    }
};
