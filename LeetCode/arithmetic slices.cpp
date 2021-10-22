class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return 0;
        vector<int> dp(n, 0);
        
        int ans = 0;
        for(int i=1; i<n-1; i++){
            if(nums[i] - nums[i-1] == nums[i+1] - nums[i]){
                dp[i] = dp[i-1]+1;
                ans = ans + dp[i];
            }
        }
        return ans;
    }
};