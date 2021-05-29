class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        bitset<100001> bitmem(0);
        for (auto i: nums){
            if (bitmem[i] == 0) bitmem[i] = 1;
            else return i;
        }
        return -1;
    }
};