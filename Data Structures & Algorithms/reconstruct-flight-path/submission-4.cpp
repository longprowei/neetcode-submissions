class Solution {
private:
    const string startNode = "JFK";
    vector<string> res;
    unordered_map<string, vector<string>> adj;
    void dfs(const string& node) {
        while (!adj[node].empty()) {
            string lastCity = adj[node].back();
            adj[node].pop_back();
            dfs(lastCity);
        }
        res.push_back(node);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto ticket : tickets) {
            adj[ticket[0]].push_back(ticket[1]);
        }

        for (auto& [source, dests] : adj) {
            sort(dests.rbegin(), dests.rend());
        }

        dfs(startNode);
        reverse(res.begin(), res.end());

        return res;
    }
};
