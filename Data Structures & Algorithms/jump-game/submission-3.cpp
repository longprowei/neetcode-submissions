class Solution {
private:
    vector<int> cache;
    bool canJump(vector<int>& nums, int i) {
        if (i >= nums.size() - 1) {
            cache[nums.size() - 1] = 1;
            return true;
        }

        if (cache[i] != -1) {
            return cache[i];
        }
        
        if (nums[i] == 0) {
            cache[i] = 0;
            return false;
        }

        if (nums[i] + i >= nums.size() - 1) {
            cache[i] = 1;
            return true;
        }
        
        for (int j = i + nums[i]; j > i; j--) {
            if (canJump(nums, j)) {
                cache[i] = 1;
                return true;
            }
        }

        cache[i] = 0;
        return false;
    }
public:
    bool canJump(vector<int>& nums) {
        cache.resize(nums.size(), -1);
        return canJump(nums, 0);
    }
};
