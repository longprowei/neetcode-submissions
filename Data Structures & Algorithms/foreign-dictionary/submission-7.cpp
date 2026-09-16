class Solution {
private:
    enum Status { UNSEEN, ACTIVE, COMPLETE };
    vector<Status> visited;
    bool dfs(unordered_map<char, unordered_set<char>>& adjLists, vector<char>& postOrder, char u) {
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

    void printGraph(unordered_map<char, unordered_set<char>>& adjLists) {
        for (auto [c, s] : adjLists) {
            cerr << c << ": ";
            for (auto ch : s) {
                cerr << ch << " ";
            }
            cerr << endl;
        }
    }
public:
    string foreignDictionary(vector<string>& words) {
        if (words.size() == 1) {
            if (words[0].size() == 1) {
                return words[0];
            } else {
                return "";
            }
        }

        unordered_map<char, unordered_set<char>> adjLists;
        for (int i = 1; i < words.size(); i++) {
            if (words[i-1].size() != words[i].size() && words[i - 1].find(words[i]) != string::npos) {
                return "";
            }

            for (int j = 0; j < words[i].size() && j < words[i - 1].size(); j++) {
                char ch1 = words[i - 1][j];
                char ch2 = words[i][j];
                if (ch1 != ch2) {
                    //cerr << "i=" << i << " j=" << j << " set " << ch1 << " to " << ch2 << endl;
                    adjLists[ch1].insert(ch2);
                    break;
                }
            }
        }

        //cerr << adjLists.size() << endl;
        //printGraph(adjLists);

        for (auto word : words) {
            for (auto c : word) {
                adjLists.try_emplace(c);
            }
        }
        //cerr << adjLists.size() << endl;
        //printGraph(adjLists);
        vector<char> postOrder;
        visited.resize(26, UNSEEN);
        for (auto [ch, s] : adjLists) {
            //cerr << "run dfs on " << ch << endl;
            if (dfs(adjLists, postOrder, ch)) {
                //cerr << "have a cycle when run dfs on " << ch << endl;
                return "";
            }
        }
        //cerr << postOrder.size() << endl;
        reverse(postOrder.begin(), postOrder.end());
        string res(postOrder.begin(), postOrder.end());

        return res;
    }
};
