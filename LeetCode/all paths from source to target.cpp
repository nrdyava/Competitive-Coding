class Solution {
    void dfs(int v, vector<vector<int>> &graph, vector<vector<int>> &ans, vector<int> &path){
        path.push_back(v);
        if(v == graph.size()-1) ans.push_back(path);
        else{
            for(auto x: graph[v]){
                dfs(x, graph, ans, path);
            }
        }
        path.pop_back();
    }
    
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(0, graph, ans, path);
        return ans;
    }
};