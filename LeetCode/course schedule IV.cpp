class Solution {
    
    
public:
    
    bool dfs(int a, int b, unordered_map<int, vector<int>> &M, vector<int> &visited){
        visited[a] = true;
        
        for(auto x: M[a]){
            if(visited[x]) continue;
            if(x==b) return true;
            if(dfs(x, b, M, visited)) return true;
        }
        return false;
    }
    
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> M;
        for(int i=0; i<prerequisites.size(); i++){
            M[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        vector<bool> ans;
        
        vector<int> visited(numCourses);
        
        for(auto q:queries){
            fill(visited.begin(), visited.end(), false);
            if(dfs(q[0], q[1], M, visited)) ans.push_back(true);
            else ans.push_back(false);
        }
        
        return ans;
    }
};