class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<int>> strIndex;

        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            strIndex[str].push_back(i);
        }

        vector<vector<string>> result;
        for (auto [str, v] : strIndex) {
            vector<string> group;
            for (int i = 0; i < v.size(); i++) {
                group.push_back(strs[v[i]]);
            }
            result.push_back(group);
        }
        return result;
    }
};
