class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> chCount;
        int res = 0;
        int left = 0;
        int maxFreq = 0;
        for (int i = 0; i < s.length(); i++) {
            chCount[s[i]]++;
            maxFreq = max(maxFreq, chCount[s[i]]);
            if (i - left + 1 - maxFreq > k) {
                chCount[s[left]]--;
                left++;
            }
            res = max(res, i - left + 1);
        }
        return res;
    }
};
