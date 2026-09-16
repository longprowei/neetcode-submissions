class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        
        int house1 = 0; //previous
        int house2 = 0; //the house of previous house
        for (int i = 1; i < nums.size(); i++) {
            int maxRob = max(house1, house2 + nums[i]);
            house2 = house1;
            house1 = maxRob;
        }
        int sitation1 = house1;

        house1 = 0, house2 = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            int maxRob = max(house1, house2 + nums[i]);
            house2 = house1;
            house1 = maxRob;
        }
        return max(house1, sitation1);
    }
};
