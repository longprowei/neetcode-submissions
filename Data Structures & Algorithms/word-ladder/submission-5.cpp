class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end() || beginWord == endWord) {
            return 0;
        }

        unordered_map<string, unordered_set<string>> neiMap;
        for (auto& word : wordList) {
            for (int i = 0; i < word.size(); i++) {
                string wild = word.substr(0, i) + "*" + word.substr(i + 1);
                neiMap[wild].insert(word);
            }
        }

        queue<string> q;
        q.push(beginWord);
        unordered_set<string> visited;
        visited.insert(beginWord);
        int len = 0;
        while (!q.empty()) {
            int sz = q.size();
            len++;
            for (int i = 0; i < sz; i++) {
                auto word = q.front();
                q.pop();
                if (word == endWord) {
                    return len;
                }
                for (int j = 0; j < word.size(); j++) {
                    string wild = word.substr(0, j) + "*" + word.substr(j + 1);
                    for (auto& nei : neiMap[wild]) {
                        if (!visited.contains(nei)) {
                            q.push(nei);
                            visited.insert(nei);
                        }
                    }
                }
            } 
        }
        return 0;
    }
};
