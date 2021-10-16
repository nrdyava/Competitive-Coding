class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==1) return 0;
        
        int dp[n];
        dp[0] = prices[0];
        for(int i=1; i<n; i++){
            dp[i] = min(dp[i-1], prices[i]);
        }
        int ans = 0;
        for(int i=1; i<n; i++){
            ans = max(prices[i] - dp[i], ans);
        }
        return ans;
    }
};