class Solution {
public:
    int nthUglyNumber(int n) {
        int twoi=0, threei=0, fivei=0;
        int ans = 1;
        vector<int> dp(n);
        dp[0] = 1;
        
        for(int i=1; i<n; i++){
            dp[i] = min({dp[twoi]*2, dp[threei]*3, dp[fivei]*5});
            if(dp[i] == dp[twoi]*2) twoi++;
            if(dp[i] == dp[threei]*3) threei++;
            if(dp[i] == dp[fivei]*5) fivei++;
        }
        return dp[n-1];
    }
};