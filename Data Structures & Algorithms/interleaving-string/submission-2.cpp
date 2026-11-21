class Solution {
private:
    unordered_map<string, bool> mem;
    bool countLetters(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }

        unordered_map<char, int> s1s2Map;
        unordered_map<char, int> s3Map;
        for (const char & c : s1) {
            s1s2Map[c]++;
        }

        for (const char & c : s2) {
            s1s2Map[c]++;
        }

        for (const char & c : s3) {
            s3Map[c]++;
        }

        return s1s2Map == s3Map;
    }

    bool isInterleave(const string& s1, const string& s2, const string& s3, int i, int j, int k) {
        if (k >= s3.size()) {
            return true;
        }

        string memKey = to_string(i) + "," + to_string(j) + "," + to_string(k);
        if (mem.contains(memKey)) {
            return mem[memKey];
        }

        bool cond1 = false;
        if (s3[k] == s1[i]) {
            cond1 = isInterleave(s1, s2, s3, i + 1, j, k + 1);
        }
        
        bool cond2 = false;
        if (s3[k] == s2[j]) {
            cond2 = isInterleave(s1, s2, s3, i, j + 1, k + 1);
        }

        bool ret = cond1 || cond2;
        mem[memKey] = ret;

        return ret;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (!countLetters(s1, s2, s3)) {
            return false;
        }

        return isInterleave(s1, s2, s3, 0, 0, 0);
    }
};
