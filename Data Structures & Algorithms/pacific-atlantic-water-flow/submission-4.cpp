struct FlowInfo {
    bool visited;
    bool canReach;
};

class Solution {
private:
    int ROWS, COLS;
    static constexpr pair<int, int> DELTA[4] = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};

    void dfsCheck(vector<vector<int>>& heights, vector<vector<FlowInfo>>& flowInfo, 
            int r, int c) {
        if (flowInfo[r][c].visited) {
            return;
        }

        flowInfo[r][c].visited = true;
        flowInfo[r][c].canReach = true;
        for (auto [dr, dc] : DELTA) {
            int nr = r + dr;
            int nc = c + dc;
            if (nr < 0 || nc < 0 || nr >= ROWS || nc >= COLS) {
                continue;
            }
            
            if (heights[r][c] <= heights[nr][nc]) {
                dfsCheck(heights, flowInfo, nr, nc);
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROWS = heights.size();
        COLS = heights[0].size();
        vector<vector<FlowInfo>> flowInfoPac(ROWS, vector<FlowInfo>(COLS));
        vector<vector<FlowInfo>> flowInfoAtl(ROWS, vector<FlowInfo>(COLS));

        for (int i = 0; i < ROWS; i++) {
            dfsCheck(heights, flowInfoPac, i, 0);
        }

        for (int j = 1; j < COLS; j++) {
            dfsCheck(heights, flowInfoPac, 0, j);
        }

        for (int i = 0; i < ROWS; i++) {
            dfsCheck(heights, flowInfoAtl, i, COLS - 1);
        }

        for (int j = 0; j < COLS - 1; j++) {
            dfsCheck(heights, flowInfoAtl, ROWS - 1, j);
        }

        vector<vector<int>> res;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (flowInfoPac[i][j].canReach && flowInfoAtl[i][j].canReach) {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};
