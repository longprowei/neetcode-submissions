class Solution {
private:
    unordered_set<string> res;
    void backTracking(int n, string curr, int leftOpen, int totalLeft) {
        if (curr.size() == n * 2) {
            res.insert(curr);
            return;
        }

        // close a parenthes
        if (leftOpen > 0) {
            backTracking(n, curr + ")", leftOpen - 1, totalLeft);
        }

        // don't close
        if (totalLeft < n) {
            backTracking(n, curr + "(", leftOpen + 1, totalLeft + 1);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        backTracking(n, "(", 1, 1);
        return vector<string>(res.begin(), res.end());
    }
};
