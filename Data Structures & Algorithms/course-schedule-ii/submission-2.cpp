class Solution {
private:
    enum Status { UNSEEN, VISITING, COMPLETE };
    vector<int> res;
    bool hasCycle(int node, vector<vector<int>>& adjList, vector<Status>& visitStatus) {        
        if (visitStatus[node] == COMPLETE) {
            return false;
        }

        visitStatus[node] = VISITING;
        for (auto v : adjList[node]) {
            if (visitStatus[v] == VISITING || hasCycle(v, adjList, visitStatus)) {
                return true;
            }
        }

        visitStatus[node] = COMPLETE;
        res.push_back(node);
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses, vector<int>());

        for (auto prereq : prerequisites) {
            int u = prereq[0];
            int v = prereq[1];
            adjList[u].push_back(v);
        }

        vector<Status> visitStatus(numCourses, UNSEEN);
        for (int i = 0; i < numCourses; i++) {
            if (hasCycle(i, adjList, visitStatus)) {
                return vector<int>();
            }
        }

        return res;
    }
};
