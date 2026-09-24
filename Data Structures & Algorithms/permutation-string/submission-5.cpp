class Solution {
private:
    const int LETTERS = 26;
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }

        vector<int> s1Freq(LETTERS, 0);
        vector<int> s2Freq(LETTERS, 0);
        for (int i = 0; i < s1.size(); i++) {
            s1Freq[s1[i] - 'a']++;
            s2Freq[s2[i] - 'a']++;
        }

        int matched = 0;
        for (int i = 0; i < LETTERS; i++) {
            if (s1Freq[i] == s2Freq[i]) {
                matched++;
            }
        }

        int l = 0; // left pointer
        for (int r = s1.size(); r < s2.size(); r++) {
            if (matched == LETTERS) {
                return true;
            }

            int index = s2[r] - 'a';
            s2Freq[index]++;
            if (s1Freq[index] == s2Freq[index]) {
                matched++;
            } else if(s1Freq[index] + 1 == s2Freq[index]) {
                // from match become not match anymore
                matched--;
            }

            int leftIndex = s2[l] - 'a';
            s2Freq[leftIndex]--;
            if (s1Freq[leftIndex] == s2Freq[leftIndex]) {
                matched++;
            } else if (s1Freq[leftIndex] - 1 == s2Freq[leftIndex]) {
                // just become unmatched
                matched--;
            }
            l++;
        }

        if (matched == LETTERS) {
            return true;
        }

        return false; 
    }
};
