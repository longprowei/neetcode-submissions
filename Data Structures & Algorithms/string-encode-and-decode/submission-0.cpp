class Solution {
public:

    string encode(vector<string>& strs) {
        string result;
        for (string str : strs) {
            result += static_cast<char>(str.length()) + str;
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        size_t len = s.length();
        int i = 0;
        while (i < len) {
            unsigned char ch = s[i++];
            result.push_back(s.substr(i, ch));
            i += ch;
        }
        return result;
    }
};
