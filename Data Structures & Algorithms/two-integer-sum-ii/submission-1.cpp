class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            int twoSum = numbers[left] + numbers[right];
            if (twoSum == target) {
                return {left + 1, right + 1};
            } else if(twoSum > target) {
                right--;
            } else {
                left++;
            }
        }
        return {0, 1};
    }
};
