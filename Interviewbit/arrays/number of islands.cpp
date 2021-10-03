class Solution {
public:
    
    vector<vector<int>> visited;
    bool isvalid(int i, int j, int n, int m){
        if(i>=0 && j>=0 && i<n && j<m)
            return true;
        return false;
    }
    
    void dfs(int i, int j, vector<vector<char>>& grid){
        visited[i][j] = 1;
        int x[4] = {0, -1, 0, 1};
        int y[4] = {-1, 0, 1, 0};
        
        for(int k=0;k<4;k++){
            if(isvalid(i+x[k], j+y[k], grid.size(), grid[0].size()) && grid[i+x[k]][j+y[k]] =='1' && !visited[i+x[k]][j+y[k]]){
                dfs(i+x[k], j+y[k], grid);
            }
        }
        return;
        
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        
        for(int i=0;i<grid.size();i++){
            vector<int> temp;
            for(int j=0;j<grid[i].size();j++){
                temp.push_back(0);
                // cout<<temp[j]<<" ";
            }
            visited.push_back(temp);
            // cout<<"\n";
        }
        int ans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!visited[i][j] && grid[i][j] == '1')
                {
                    dfs(i, j, grid);
                    ans+=1;
                }   
                
            }
        }
        return ans;
    }
};