class Solution {
public:
    bool isValid(unordered_map<char, int> &mpSouce, unordered_map<char, int> &mpTarget) {
        bool ret = true;
        for (auto [ch, cnt] : mpTarget) {
            if (!mpSouce.contains(ch) || mpSouce[ch] < cnt) {
                ret = false;
                break;
            }
        }

        return ret;
    }

    string minWindow(string s, string t) {
        unordered_map<char, int> tFreq;
        for (char c : t) {
            tFreq[c]++;
        }

        string minSubStr;
        int minL = -1;
        int minLen = s.size() + 1;
        unordered_map<char, int> sFreq;
        int left = 0;
        for (int i = 0; i < s.size(); i++) {
            sFreq[s[i]]++;
            if (i - left + 1 < t.length()) continue;

            while (isValid(sFreq, tFreq)) {
                if (i - left + 1 < minLen) {
                    minL = left;
                    minLen = i - left + 1;
                }
                sFreq[s[left]]--;
                left++;
            }
        }

        if (minL != -1) {
            minSubStr = s.substr(minL, minLen);
        }

        return minSubStr;
    }
};
