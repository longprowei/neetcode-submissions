class Solution {
private:
    int ROWS, COLS;
    static constexpr pair<int, int> DELTAS[4]
        = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int r, int c) {
        if (visited[r][c]) {
            return;
        }

        visited[r][c] = true;
        for (auto [dr, dc] : DELTAS) {
            int newR = r + dr;
            int newC = c + dc;
            if (newR >= 0 && newR < ROWS && newC >= 0 && newC < COLS &&
                    grid[newR][newC] == '1') {
                dfs(grid, visited, newR, newC);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();
        vector<vector<bool>> visited(ROWS, vector<bool>(COLS));
        
        int islandsCount = 0;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    islandsCount++;
                    dfs(grid, visited, i, j);
                }
            }
        }
        return islandsCount;
    }
};
