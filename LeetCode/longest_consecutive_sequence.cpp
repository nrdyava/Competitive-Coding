class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us(nums.begin(), nums.end());
        int LCS = 0, l, r;
        
        for(int i=0; i < nums.size(); i++){
            l = nums[i];
            r = nums[i]+1;
            while(us.count(l) == 1) us.erase(us.find(l--));
            while(us.count(r) == 1) us.erase(us.find(r++));
            LCS = max(LCS, r - l - 1);
        }
        return LCS;
    }
};