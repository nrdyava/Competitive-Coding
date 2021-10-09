class Solution {
    bool bfs(unordered_map<int, vector<int>> &graph, int v, vector<int> &colors){
        queue<int> q;
        colors[v] = 0;
        q.push(v);
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            for(auto child: graph[curr]){
                if(colors[child] == -1){
                    colors[child] = 1-colors[curr];
                    q.push(child);
                }
                else if(colors[curr] == colors[child]){
                    return false;
                }
            }
        }
        
        return true;
    }
    
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> graph;
        for(int i=0; i<dislikes.size(); i++){
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        vector<int> colors(n+1, -1);
        for(int i=1; i<=n; i++){
            if(colors[i] == -1){
                if(!bfs(graph, i, colors)) return false;
            }
        }
        return true;
    }
};