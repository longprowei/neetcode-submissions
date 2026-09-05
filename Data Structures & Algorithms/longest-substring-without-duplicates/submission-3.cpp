class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndexMap;

        int maxLen = 0;
        int startIndex = 0;
        for (int i = 0; i < s.length(); i++) {
            if (charIndexMap.contains(s[i])) {
                maxLen = max(maxLen, static_cast<int>(charIndexMap.size()));
                int index = charIndexMap[s[i]];
                // remove the all elements before index i inside s
                for (int j = index; j >= startIndex; j--) {
                    if (charIndexMap.erase(s[j]) != 1) {
                        // if we cannot erase the element, we don't need to erase more
                        break;
                    }
                }
                startIndex = index + 1;
            }
            charIndexMap[s[i]] = i;
        }
        maxLen = max(static_cast<int>(charIndexMap.size()), maxLen);
        return maxLen;
    }
};
