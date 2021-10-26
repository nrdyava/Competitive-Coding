class Solution {
public:
    int solver(vector<int> nums){
        int n = nums.size();
        int maxx = *max_element(nums.begin(), nums.end());
        int minn = *min_element(nums.begin(), nums.end());
        
        vector<vector<int>> dp(n+1, vector<int>(maxx-minn+1, 1));
        int ans = 2;
        
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                int diff = nums[i] - nums[j];
                if(diff >= 0){
                    dp[i][diff] = max(dp[i][diff], dp[j][diff]+1);
                    ans = max(ans, dp[i][diff]);
                }
            }
        }
        return ans;
    }
    
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n<=2) return n;
        
        int ans = 2;
        ans = max(ans, solver(nums));
        reverse(nums.begin(), nums.end());
        ans = max(ans, solver(nums));
        
        return ans;
    }
};