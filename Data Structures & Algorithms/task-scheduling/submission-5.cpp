class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> taskCounter;

        for (char c : tasks) {
            taskCounter[c]++;
        }

        priority_queue<pair<int, char>> pq;
        for (auto [task, cnt] : taskCounter) {
            pq.emplace(cnt, task);
        }
        
        int cpuCycle = 0;
        queue<pair<int, char>> cooldown;
        while (!pq.empty() || !cooldown.empty()) {
            cpuCycle++;

            
            while (!cooldown.empty() && cooldown.front().first <= cpuCycle) {
                auto [cycle, task] = cooldown.front();
                pq.emplace(taskCounter[task], task);
                cooldown.pop();
            }

            if (pq.empty()) continue;

            auto [cnt, task] = pq.top();
            pq.pop();
            if (cnt > 1) {
                cooldown.push({cpuCycle + n + 1, task});
            }
            taskCounter[task]--;
        }

        return cpuCycle;
    }
};
