class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> timeMap;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!timeMap.contains(key)) {
            return "";
        }

        auto &vec = timeMap[key];
        auto it = upper_bound(vec.begin(), vec.end(), timestamp, 
            [](const int & value, const pair<int, string>& elem){
                return value < elem.first;
            });

        if (it == vec.begin()) {
            return "";
        } else {
            it--;
            return it->second;
        }
    }
};
