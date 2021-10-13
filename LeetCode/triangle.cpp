class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp = triangle;
        
        dp[0][0] = triangle[0][0];
        
        for(int i=1; i<triangle.size(); i++){
            dp[i][0] = dp[i-1][0] + triangle[i][0];
            dp[i][i] = dp[i-1][i-1] + triangle[i][i];
            
            for(int j = 1; j<i; j++){
                dp[i][j] = triangle[i][j] + min(dp[i-1][j], dp[i-1][j-1]);
            }
        }
        
        return *min_element(dp[triangle.size()-1].begin(), dp[triangle.size()-1].end());
    }
};