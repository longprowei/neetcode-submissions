class Solution {
private:
    vector<string> res;
    unordered_map<char, string> numsMapping;
    void backTracking(string& digits, int i, string path) {
        if (i >= digits.length() && !path.empty()) {
            res.push_back(path);
            return;
        }

        string letters = numsMapping[digits[i]];
        for (int j = 0; j < letters.size(); j++) {
            backTracking(digits, i + 1, path + letters[j]);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        numsMapping = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        backTracking(digits, 0, "");
        
        return res;
    }
};
