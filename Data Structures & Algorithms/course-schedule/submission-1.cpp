class Solution {
private:
    enum VisitStatus { UNSEEN, ACTIVE, COMPLETE };
    vector<VisitStatus> status;
    bool hasCycle(vector<vector<int>>& graph, int u) {
        if (status[u] != UNSEEN) {
            return false;
        }

        status[u] = ACTIVE;
        for (auto v : graph[u]) {
            if (status[v] == ACTIVE || hasCycle(graph, v)) {
                return true;
            }
        }
        status[u] = COMPLETE;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        status.resize(numCourses);
        for (auto p : prerequisites) {
            graph[p[0]].push_back(p[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (hasCycle(graph, i)) {
                return false;
            } 
        }

        return true;
    }
};
