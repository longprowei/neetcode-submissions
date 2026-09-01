class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            char leftCh = s[i];
            char rightCh = s[j];
            if (!isalpha(leftCh) && !isdigit(leftCh)) {
                i++;
                continue;
            }

            if (!isalpha(rightCh) && !isdigit(rightCh)) {
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
