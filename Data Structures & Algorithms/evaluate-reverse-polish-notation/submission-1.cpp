class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> tokenStack;
        
        for (const auto &token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int num2 = tokenStack.top();
                tokenStack.pop();
                int num1 = tokenStack.top();
                tokenStack.pop();
          
                if (token == "+") {
                    tokenStack.push(num1 + num2);
                } else if (token == "-") {
                    tokenStack.push(num1 - num2);
                } else if (token == "/") {
                    tokenStack.push(num1 / num2);
                } else if (token == "*") {
                    tokenStack.push(num1 * num2);
                }
            } else {
                tokenStack.push(stoi(token));
            }
        }

        return tokenStack.top();
    }
};
