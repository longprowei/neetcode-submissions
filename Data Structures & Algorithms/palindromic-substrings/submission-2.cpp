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
            checkPalin(s, i, i);
            checkPalin(s, i, i + 1);
        }
        return res;
    }
};
