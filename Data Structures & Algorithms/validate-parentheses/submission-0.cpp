class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) {
            return false;
        }
        
        stack<char> charStack;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                charStack.push(c);
            } else {
                if (charStack.empty()) {
                    return false;
                }

                char popped = charStack.top();
                charStack.pop();
                if (c == ')' && popped != '(') {
                    return false;
                }
                
                if (c == '}' && popped != '{') {
                    return false;
                }

                if (c == ']' && popped != '[') {
                    return false;
                }
            }
        }

        if (!charStack.empty()) {
            return false;
        }

        return true;
    }
};
