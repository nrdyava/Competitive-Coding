class Solution {
    vector<int> tpsort(unordered_map<int, vector<int>> &M, vector<int> &indegree, stack<int> &S, vector<int> &ans){
        while(!S.empty()){
            int curr = S.top();
            S.pop();
            
            ans.push_back(curr);
            
            for(auto x: M[curr]){
                indegree[x]--;
                if(indegree[x] == 0) S.push(x);
            }
        }
        for(auto x: indegree){
            if(x != 0){
                return {};
            }
        }
        return ans;
    }
    
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> M;
        for(int i=0; i<prerequisites.size(); i++){
            M[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<int> indegree(numCourses, 0);
        stack<int> S;
        
        for(int i=0; i<numCourses; i++){
            for(int j=0; j<M[i].size(); j++){
                indegree[M[i][j]]++;
            }
        }
        
        for(int i=0; i<indegree.size(); i++){
            if(indegree[i]==0) S.push(i);
        }
        
        vector<int> ans;
        return tpsort(M, indegree, S, ans);
    }
};