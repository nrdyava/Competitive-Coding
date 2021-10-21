class Solution {
    bool dfs(int v, vector<bool> &visited, int dest, unordered_map<int, vector<int>> &M){
        if(v == dest){
            return M[v].size()==0;
        }
        
        if(visited[v] || M[v].size() == 0){
            return false;
        }
        
        visited[v] = true;
        
        for(int child: M[v]){
            if(!dfs(child, visited, dest, M)) return false;
        }
        visited[v] = false;
        
        return true;
    }
    
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> M;
        for(int i=0; i<edges.size(); i++){
            M[edges[i][0]].push_back(edges[i][1]);
        }
        
        vector<bool> visited(n+1, false);
        
        return dfs(source, visited, destination, M);
        
        
    }
};