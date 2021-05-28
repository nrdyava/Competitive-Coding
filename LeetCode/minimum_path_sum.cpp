class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        if (m==1 && n==1) return grid[0][0];
        
        for(int i=1;i<m;i++) grid[i][0] = grid[i][0] + grid[i-1][0];
        for(int j=1;j<n;j++) grid[0][j] = grid[0][j] + grid[0][j-1];
        for (int i=1;i<m;i++){
            for (int j=1;j<n;j++){
                grid[i][j] = grid[i][j] + min(grid[i][j-1],grid[i-1][j]);
            }
        }
        return grid[m-1][n-1];
    }
};