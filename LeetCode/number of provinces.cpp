class Solution {
    void dfs(int v, vector<vector<int>>& isConnected, vector<int> &visited){
        if(visited[v]) return;
        
        visited[v] = true;
        for(int j=0; j<isConnected.size(); j++){
            if(isConnected[v][j]) dfs(j, isConnected, visited);
        }
        return;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, false);
        
        int ans = 0;
        
        for(int i=0; i<n; i++){
            if(!visited[i]){
                ans++;
                dfs(i, isConnected, visited);
            }
        }
        
        return ans;
    }
};