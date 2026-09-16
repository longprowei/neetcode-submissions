class Solution {
private:
    enum Status { UNSEEN, ACTIVE, COMPLETE };
    vector<Status> visited;
    bool dfs(unordered_map<char, unordered_set<char>>& adjLists, string& postOrder, char u) {
        if (visited[u - 'a'] != UNSEEN) {
            return false;
        }
        visited[u - 'a'] = ACTIVE;
        
        for (auto v : adjLists[u]) {
            if (visited[v - 'a'] == ACTIVE || dfs(adjLists, postOrder, v)) {
                return true;
            }
        }
        visited[u - 'a'] = COMPLETE;
        postOrder.push_back(u);
        return false;
    }
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adjLists;
        for (int i = 1; i < words.size(); i++) {
            int j;
            for (j = 0; j < words[i].size() && j < words[i - 1].size(); j++) {
                char ch1 = words[i - 1][j];
                char ch2 = words[i][j];
                if (ch1 != ch2) {
                    adjLists[ch1].insert(ch2);
                    break;
                }
            }
            if (j >= words[i].size() && j < words[i - 1].size()) {
                // second word is a substring of the first word
                return "";
            }
        }

        for (auto word : words) {
            for (auto c : word) {
                adjLists.try_emplace(c);
            }
        }

        string res;
        visited.resize(26, UNSEEN);
        for (auto [ch, s] : adjLists) {
            if (dfs(adjLists, res, ch)) {
                return "";
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
