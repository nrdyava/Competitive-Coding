class Solution {
    bool isvalid(int i, int j, int n){
        if(i<0 || i>=n || j<0 || j>= n) return false;
        return true;
    }
    
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == 0) dp[i][j] = matrix[i][j];
                else{
                    int temp = INT_MAX;
                    if(isvalid(i-1, j-1, n)) temp = min(temp, dp[i-1][j-1]);
                    if(isvalid(i-1, j, n)) temp = min(temp, dp[i-1][j]);
                    if(isvalid(i-1, j+1, n)) temp = min(temp, dp[i-1][j+1]);
                    dp[i][j] = matrix[i][j] + temp;
                }
            }
        }
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};