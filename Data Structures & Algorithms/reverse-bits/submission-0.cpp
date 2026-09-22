class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int i = 0, j = 31;
        while (i < j) {
            res |= ((n >> i) & 1) << j;
            res |= ((n >> j) & 1) << i;
            i++;
            j--;
        }
        return res;
    }
};
