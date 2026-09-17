class Solution {
private:
    int res = 0;
    void checkPalin(const string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            res++;
            left--;
            right++;
        }
    }
public:
    int countSubstrings(string s) {
        for (int i = 0; i < s.size(); i++) {
            int left = i;
            int right = i;
            checkPalin(s, left, right);
            if (i + 1 < s.size()) {
                right = i + 1;
                checkPalin(s, left, right);
            }
        }
        return res;
    }
};
