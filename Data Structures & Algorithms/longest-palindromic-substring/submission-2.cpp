class Solution {
private:
    int resLen = 1; // as s is 1 minimal
    int resIndex = 0;
    void updatePalindromRes(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            int newResSize = right - left + 1;
            if (newResSize > resLen) {
                resLen = newResSize;
                resIndex = left;
            }
            left--;
            right++;
        }
    }
public:
    string longestPalindrome(string s) {
        for (int i = 1; i < s.size(); i++) {
            int left = i - 1;
            int right = i + 1;
            // check odd length parlindrom
            updatePalindromRes(s, left, right);
            right = i;
            // check even length parlindrom
            updatePalindromRes(s, left, right);
        }

        return s.substr(resIndex, resLen);
    }
};
