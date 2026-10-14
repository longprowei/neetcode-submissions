class Solution {
private:
    vector<vector<string>> res;
    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1;
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }

    void addPalindrome(string s, vector<string>& curr) {
        if (s.empty()) {
            res.push_back(curr);
            return;
        }

        for (int i = 0; i < s.length(); i++) {
            if (i == 0 || isPalindrome(s.substr(0, i + 1))) {
                curr.push_back(s.substr(0, i + 1));
                addPalindrome(s.substr(i + 1, s.length() - i - 1), curr);
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        addPalindrome(s, curr);
        return res;
    }
};
