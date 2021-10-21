class Solution {
    bool dfs(int v, unordered_map<int, vector<int>> &M, vector<bool> &visited, int &end){
        if(visited[v]) return false;
        if(v == end) return true;
        
        visited[v] = true;
        for(int child:M[v]){
            if(dfs(child, M, visited, end)) return true;
        }
        return false;
    }
    
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        unordered_map<int, vector<int>> M;
        vector<bool> visited(n, false);
        
        for(int i=0; i<edges.size(); i++){
            M[edges[i][0]].push_back(edges[i][1]);
            M[edges[i][1]].push_back(edges[i][0]);
        }
        
        return dfs(start, M, visited, end);
    }
};