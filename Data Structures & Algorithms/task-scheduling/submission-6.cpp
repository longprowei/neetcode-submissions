class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> taskCounter(26);
        for (char c : tasks) {
            taskCounter[c - 'A']++;
        }

        sort(taskCounter.begin(), taskCounter.end());
        int maxCounter = taskCounter[25];
        int idel = (maxCounter - 1) * n;
        for (int i = 24; i >= 0; i--) {
            idel -= min(taskCounter[i], maxCounter - 1);
        }

        return max(0, idel) + tasks.size();
    }
};
