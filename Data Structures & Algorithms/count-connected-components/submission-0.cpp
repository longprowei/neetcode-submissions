class DSU {
private:
    vector<int> parent;
    vector<int> compSize;
public:
    int compCount;
    DSU(int n) : compCount(n) {
        parent.resize(n + 1);
        compSize.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            compSize[i] = 1;
        }
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        
        return parent[u];
    }

    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) {
            return;
        }

        compCount--;
        if (compSize[u] >= compSize[v]) {
            compSize[u] += compSize[v];
            parent[v] = u;
        } else {
            compSize[v] += compSize[u];
            parent[u] = v;
        }
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for (const auto& edge : edges) {
            dsu.join(edge[0], edge[1]);
        }

        return dsu.compCount;
    }
};
