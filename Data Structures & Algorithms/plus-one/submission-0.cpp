class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            int newDigit = digits[i] + carry;
            carry = newDigit / 10;
            newDigit %= 10;
            res.push_back(newDigit);
        }

        if (carry == 1) {
            res.push_back(carry);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
