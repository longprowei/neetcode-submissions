class TimeMap {
private:
    unordered_map<string, vector<int>> timeMap;
    unordered_map<int, string> values;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key].push_back(timestamp);
        values[timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (!timeMap.contains(key)) {
            return "";
        }

        auto vec = timeMap[key];
        auto it = lower_bound(vec.begin(), vec.end(), timestamp);

        if (it != vec.end() && *it == timestamp) {
            return values[timestamp];
        }

        if (it == vec.begin()) {
            return "";
        }
      
        it--;
        return values[*it];
    }
};
