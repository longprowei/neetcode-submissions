class Solution {
private:
    unordered_map<string, bool> mem;
    bool wordBreakRec(const string &s, vector<string>& wordDict) {
        if (mem.contains(s)) {
            return mem[s];
        }

        if (s.empty()) {
            return true;
        }

        bool succ = false;
        for (auto word : wordDict) {
            if (s.size() >= word.size() && s.starts_with(word)) {
                string newStr = s.substr(word.size(), s.size() - word.size());
                if (wordBreakRec(newStr, wordDict)) {
                    succ = true;
                    break;
                }
            }
        }
        mem[s] = succ;
        return succ;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        return wordBreakRec(s, wordDict);
    }
};
