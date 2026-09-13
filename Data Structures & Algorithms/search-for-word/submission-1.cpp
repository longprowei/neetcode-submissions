class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        cerr << word << endl;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                unordered_set<string> used;
                used.insert(to_string(i) + "," + to_string(j));
                string curr;
                curr += board[i][j];
                if(dfs(board, word, curr, {i, j}, used)) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    bool dfs(vector<vector<char>>& board, string word, string curr, 
        pair<int,int> pos, unordered_set<string>& used) {
        
        if (word == curr) {
            return true;
        }

        if (word.size() <= curr.size()) {
            return false;
        }

        pair<int, int> delta[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        auto [r, c] = pos;
        for (auto [dr, dc] : delta) {
            int newR = r + dr;
            int newC = c + dc;
            //cerr << "curr pos [" << r << "," << c << "], newPos [" << newR << "," << newC << "]" << endl;
            if (newR >= 0 && newR < board.size() && newC >=0 && newC < board[0].size()) {
                string posStr = to_string(newR) + "," + to_string(newC);
                if (used.contains(posStr)) {
                    continue;
                }

                used.insert(posStr);
                if(dfs(board, word, curr + board[newR][newC], {newR, newC}, used)) {
                    return true;
                }
                used.erase(posStr);
            }
        }

        return false;
    }
};
