class Solution {
public:
    int rob(vector<int>& nums) {
        int house1 = 0; // prevous house get robbed value
        int house2 = 0; // the house before the prevous house get robbed value;
        for (auto num : nums) {
            int maxRob = max(house2 + num, house1);
            house2 = house1;
            house1 = maxRob;
        }
        return house1;
    }
};
