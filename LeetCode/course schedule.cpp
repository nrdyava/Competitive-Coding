class Solution {

bool dfs(vector<bool> &visited, vector<bool> &dfs_stack, int v, unordered_map<int, vector<int>> &M){
    if(!visited[v]){
        visited[v] = true;
        dfs_stack[v] = true;
        
        for(auto child: M[v]){
            if(!visited[child] && dfs(visited, dfs_stack, child, M)){
                return true;
            }
            else if(dfs_stack[child]) return true;
        }
    }
    dfs_stack[v] = false;
    return false;
}
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> M;
        for(int i=0; i<prerequisites.size(); i++){
            M[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<bool> visited(numCourses, false);
        vector<bool> dfs_stack(numCourses, false);
        
        for(int i=0; i<numCourses; i++){
            if(dfs(visited, dfs_stack, i, M)) return false;
        }
        return true;
    }
};