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

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end(), [](auto &x, auto &y){return x[0]<y[0];});
        
        UnionFind uf(n);
        
        for(int i=0; i<logs.size(); i++){
            uf.unionSet(logs[i][1], logs[i][2]);
            if(uf.getCount()==1) return logs[i][0];
        }
        return -1;
    }
};