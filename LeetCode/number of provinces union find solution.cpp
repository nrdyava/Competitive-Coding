class Solution {
    class UnionFind{
    public:
    vector<int> rank;
    vector<int> root;
    int count;
    
    UnionFind(int sz){
        count = sz;
        root.resize(sz);
        rank.resize(sz);
        
        for(int i=0; i<sz; i++){
            root[i] = i;
            rank[i] = 1;
        }
    }
    
    int find(int x){
        if(x == root[x]) return x;
        return root[x] = find(root[x]);
    }
    
    void unionSet(int x, int y){
        int root_x = find(x);
        int root_y = find(y);
        
        if(root_x != root_y){
            if(rank[root_x] > rank[root_y]){
                root[root_y] = root_x;
            }
            else if(rank[root_x] < rank[root_y]){
                root[root_x] = root_y;
            }
            else{
                root[root_x] = root_y;
                rank[root_y]++;
            }
            count--;
        }
    }
    
    int getCount(){
        return count;
    }
};
    
    public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind uf(n);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j]) uf.unionSet(i, j);
            }
        }
        return uf.getCount();
    }
};