class Solution {
private:
    int ROWS, COLS;
    static constexpr pair<int, int> DELTA[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();
        queue<tuple<int, int, int>> q; // row, colomn, dist

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == 0) {
                    q.emplace(r, c, 0);
                }
            }
        }
        
        while (!q.empty()) {
            auto [r, c, dist] = q.front();
            q.pop();
            for (auto [dr, dc] : DELTA) {
                int nr = dr + r;
                int nc = dc + c;
                if (nr >= 0 && nc >= 0 && nr < ROWS && nc < COLS && grid[nr][nc] == INT_MAX) {
                    grid[nr][nc] = grid[r][c] + 1;
                    q.emplace(nr, nc, grid[nr][nc]);
                }
            }
        }
    }
};
