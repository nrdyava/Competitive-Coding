class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[n];
        dp[n-1] = 0;
        int maxr = prices[n-1];
    
        for(int i=n-2; i>=0; i--){
            maxr = max(maxr, prices[i]+((i+2<n)?dp[i+2]:0));
            dp[i] = max(dp[i+1], maxr - prices[i]);
        }
        return dp[0];
    }
};