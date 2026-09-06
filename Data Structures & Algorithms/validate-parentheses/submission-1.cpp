class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) {
            return false;
        }

        stack<char> charStack;
        unordered_map<char, char> closeToOpen = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        for (char c : s) {
            if (closeToOpen.contains(c)) {
                if (!charStack.empty() && closeToOpen[c] == charStack.top()) {
                    charStack.pop();
                } else {
                    return false;
                }
            } else {
                charStack.push(c);
            }
        }

        return charStack.empty();
    }
};
