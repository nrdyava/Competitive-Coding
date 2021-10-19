class UnionFind{
    public:
    vector<int> root;
    vector<int> rank;
    int count;
    
    UnionFind(int sz){
        root.resize(sz);
        rank.resize(sz);
        count = sz;
        
        for(int i=0; i<sz; i++){
            root[i] = i;
            rank[i] = 1;
        }
    }
    
    int find(int x){
        if(x == root[x]) return x;
        return root[x] = find(root[x]);
    }
    
    int make_union(int x, int y){
        int root_x = find(x);
        int root_y = find(y);
        
        if(root_x == root_y) return 0;
        else{
            if(rank[root_x] > rank[root_y]) root[root_y] = root_x;
            else if(rank[root_x] < rank[root_y]) root[root_x] = root_y;
            else{
                root[root_x] = root_y;
                rank[root_y]++;
            }
            count--;
            return 1;
        }
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        
        for(int i=0; i<edges.size(); i++){
            if(uf.make_union(edges[i][0], edges[i][1]) == 0) return false;
        }
        if(uf.count != 1) return false;
        return true;
    }
};