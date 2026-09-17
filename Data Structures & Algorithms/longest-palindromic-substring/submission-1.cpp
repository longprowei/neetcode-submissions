class Solution {
private:
    string res;
    void updatePalindromRes(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            int newResSize = right - left + 1;
            if (newResSize > res.size()) {
                res = s.substr(left, newResSize);
            }
            left--;
            right++;
        }
    }
public:
    string longestPalindrome(string s) {
        res += s[0];
        for (int i = 1; i < s.size(); i++) {
            int left = i - 1;
            int right = i + 1;
            // check odd length parlindrom
            updatePalindromRes(s, left, right);
            if (s[i] == s[left]) {
                if (res.size() < 2) {
                    res = s.substr(i - 1, 2);
                }
                left--;
                // check even length parlindrom
                updatePalindromRes(s, left, right);
            }
        }

        return res;
    }
};
