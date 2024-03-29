class Solution {
public:
    
    int find_par(int u, vector<int> &par){
        if(par[u] == u)
            return u;
        return par[u] = find_par(par[u], par);
    }
    
    void union_sets(int u, int v, vector<int> &par){
        int par_u = find_par(u, par);
        int par_v = find_par(v, par);
        if(par_u != par_v){
            par[par_v] = par_u;
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> par(1001);
        for(int i = 0; i < 1001; ++i)
            par[i] = i;
        vector<int> ans;
        for(int i = 0; i < edges.size(); ++i){
            if(find_par(edges[i][0], par) == find_par(edges[i][1], par)){
                ans.push_back(edges[i][0]);
                ans.push_back(edges[i][1]);
            }
            else
                union_sets(edges[i][0], edges[i][1], par);
        }
        return ans;
    }
};