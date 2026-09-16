class Solution {
    vector<bool> visited;
    int visitedCount = 0;
private:
    bool hasCycle(vector<vector<int>>& adjLists, int u, int from) {
        if (visited[u]) {
            return true;
        }

        visited[u] = true;
        visitedCount++;
        for (int v : adjLists[u]) {
            if (v != from) {
                if (hasCycle(adjLists, v, u)) {
                    return true;
                }
            }
        }
        return false;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjLists(n);
        visited.resize(n, false);
        for (auto edge : edges) {
            adjLists[edge[0]].push_back(edge[1]);
            adjLists[edge[1]].push_back(edge[0]);
        }
        if (hasCycle(adjLists, 0, -1)) {
            return false;
        }
        
        return visitedCount == n;
    }
};
