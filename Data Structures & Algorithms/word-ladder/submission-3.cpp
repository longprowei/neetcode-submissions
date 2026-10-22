class Solution {
private:
    bool oneLetterDiff(string& a, string& b) {
        int diffCount = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                diffCount++;
                if (diffCount > 1) {
                    return false;
                }
            }
        }

        return diffCount == 1;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, unordered_set<string>> adj;

        // begin word to wordlist
        for (auto& word : wordList) {
            if (oneLetterDiff(beginWord, word)) {
                adj[beginWord].insert(word); // I don't need the other direction edge
            }
        }

        // wordList words to words
        for (int i = 0; i < wordList.size(); i++) {
            for (int j = i + 1; j < wordList.size(); j++) {
                if (oneLetterDiff(wordList[i], wordList[j])) {
                    adj[wordList[i]].insert(wordList[j]);
                    adj[wordList[j]].insert(wordList[i]);
                }
            }
        }

        queue<pair<string, int>> q; // word, pathLenght
        q.emplace(beginWord, 1);
        unordered_set<string> visited;
        visited.insert(beginWord);
        while (!q.empty()) {
            auto [word, len] = q.front();
            if (word == endWord) {
                return len;
            }
            
            q.pop();

            for (auto& nei : adj[word]) {
                if (!visited.contains(nei)) {
                    visited.insert(nei);
                    q.emplace(nei, len + 1);
                }
            }
            
        }

        return 0; 
    }
};
