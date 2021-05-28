class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int summ = 0;
        for (auto it: nums){
            summ+=it;
            ans = max(ans, summ);
            summ = max(summ, 0);
        }
        return ans;
    }
};