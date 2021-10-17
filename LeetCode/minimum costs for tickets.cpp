class Solution {
    
    int dfs(vector<int> &days, vector<int> &costs, vector<int> &dp, int i, int final_day){
        if(i == days.size()) return 0;
        if(days[i]<=final_day) return dfs(days, costs, dp, i+1, final_day);
        
        if(dp[i] != -1) return dp[i];
        
        int one_day = costs[0] + dfs(days, costs, dp, i+1, days[i]+0);
        int seven_days = costs[1] + dfs(days, costs, dp, i+1, days[i]+6);
        int thirty_days = costs[2] + dfs(days, costs, dp, i+1, days[i]+29);
        
        return dp[i] = min(min(seven_days, thirty_days), one_day);
    }
    
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366, -1);
        return dfs(days, costs, dp, 0, 0);
        
    }
};