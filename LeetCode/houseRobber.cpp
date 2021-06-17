class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        vector<int> maxRob(n, 0);
        maxRob[0] = nums[0]; maxRob[1] = max(nums[0], nums[1]);
        for(int i=2; i<n; i++){
            maxRob[i] = max(maxRob[i-2]+nums[i], maxRob[i-1]);
        }
        return maxRob[n-1];
    }
};