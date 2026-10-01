class LRUCache {
private:
    int capacity;
    list<int> keyList;
    unordered_map<int, pair<int, list<int>::iterator>> cache;
public:
    LRUCache(int capacity) : capacity(capacity) {
        
    }
    
    int get(int key) {
        if (cache.contains(key)) {
            auto [val, it] = cache[key];
            keyList.erase(it);
            cache.erase(key);
            keyList.push_back(key);
            cache[key] = {val, --keyList.end()};
            return val;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (cache.contains(key)) {
            auto [val, it] = cache[key];
            keyList.erase(it);
            cache.erase(key);
        } else if (cache.size() >= capacity) {
            int lru = keyList.front();
            keyList.pop_front();
            cache.erase(lru);
        }

        keyList.push_back(key);
        cache[key] = {value, --keyList.end()};
    }
};
