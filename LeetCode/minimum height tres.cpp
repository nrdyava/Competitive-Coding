class Solution {
    
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if(n == 1) return {0};
        if(n == 2) return {0, 1};
        
        unordered_map<int, vector<int>> g;
        vector<int> indegree(n, 0);
        vector<int> ans;
        
        for(auto edge: edges){
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
            
            indegree[edge[0]]++;
            indegree[edge[1]]++;
        }
        
        queue<int> q;
        
        for(int i=0; i<n; i++){
            if(indegree[i] == 1) q.push(i);
        }
        
        while(n>2){
            int size = q.size();
            n = n - size;
            
            while(size--){
                int curr = q.front();
                q.pop();
                
                for(auto child:g[curr]){
                    indegree[child]--;
                    if(indegree[child] == 1) q.push(child);
                }
            }
        }
        
        while(q.size() > 0){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
        
    }
};