class UnionFind {
    vector<int> parent;
    vector<int> compSize;
public:
    UnionFind(int n) {
        parent.resize(n + 1);
        compSize.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            compSize[i] = 1;
        }
    }

    int root(int u) {
        if (u == parent[u]) {
            return u;
        }
        return parent[u] = root(parent[u]);
    }

    void join(int u, int v) {
        u = root(u);
        v = root(v);
        if (u == v) {
            return;
        }

        int uSize = compSize[u];
        int vSize = compSize[v];

        if (uSize <= vSize) {
            compSize[v] += uSize;
            parent[u] = v;
        } else {
            compSize[u] += vSize;
            parent[v] = u;
        }
    }

    bool sameComp(int u, int v) {
        return root(u) == root(v);
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind unionFind(edges.size());

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            if (unionFind.sameComp(u, v)) {
                return {u, v};
            } else {
                unionFind.join(u, v);
            }
        }
        return {};
    }
};
