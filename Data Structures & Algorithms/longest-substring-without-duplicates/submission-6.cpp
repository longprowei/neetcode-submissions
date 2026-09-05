class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndexMap;

        int maxLen = 0;
        int left = 0;
        for (int i = 0; i < s.length(); i++) {
            if (charIndexMap.contains(s[i])) {
                left = max(left, charIndexMap[s[i]] + 1);
            }
            charIndexMap[s[i]] = i;
            maxLen = max(maxLen, i - left + 1);
        }
        
        return maxLen;
    }
};
