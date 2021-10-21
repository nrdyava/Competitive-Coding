class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int m = *max_element(nums.begin(), nums.end());
        vector<int> freq(m+1, 0);
        vector<int> dp(m+1, 0);
        
        for(int i=0; i<nums.size(); i++){
            freq[nums[i]]++;
        }
        
        dp[0] = 0;
        dp[1] = freq[1];
        for(int i=2; i<=m; i++){
            dp[i] = max(dp[i-1], dp[i-2]+freq[i]*i);
        }
        return dp[m];
    }
};