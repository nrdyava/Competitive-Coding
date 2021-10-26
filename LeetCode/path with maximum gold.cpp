class Solution {
public:
    bool visited[15][15];
    int helper(vector<vector<int>>& grid,int row,int col)
    {
        if(row < 0 || col < 0 || row == grid.size() || col == grid[0].size() || visited[row][col] == true)
        {
            return 0;
        }
        if(grid[row][col] == 0)
        {
            return 0;
        }
            
        visited[row][col] = true;
        
        int up = helper(grid,row-1,col);
        int down = helper(grid,row+1,col);
        int left = helper(grid,row,col-1);
        int right = helper(grid,row,col+1);
        
        visited[row][col] = false;
        return grid[row][col] + max(up,max(down,max(left,right)));
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int maxResult = 0;
        memset(visited,false,sizeof(visited));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                maxResult = max(maxResult,helper(grid,i,j));
            }
        }
        return maxResult;
    }
};