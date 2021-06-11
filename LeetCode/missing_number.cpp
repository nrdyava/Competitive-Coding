class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int summ = accumulate(nums.begin(), nums.end(), 0);
        return abs(summ - n*(n+1)/2);
    }
};