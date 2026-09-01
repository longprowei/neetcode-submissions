class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            char leftCh = s[i];
            char rightCh = s[j];
            if (!isalnum(leftCh)) {
                i++;
                continue;
            }

            if (!isalnum(rightCh)) {
                j--;
                continue;
            }

            if (tolower(leftCh) == tolower(rightCh)) {
                i++;
                j--;
            } else {
                return false;
            }
        }
        return true;
    }
};
