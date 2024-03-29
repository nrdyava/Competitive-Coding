class Solution {
public:
    
    int find(int i,vector<int> &parent){
        if(parent[i]==-1) return i;
        return parent[i]=find(parent[i],parent);
    }
    
    void unio(int a,int b,vector<int> &parent){
        int xs=find(a,parent);
        int ys=find(b,parent);
        if(xs!=ys){
           parent[ys]=xs;
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<int> parent(s.size(),-1);
        for(int i=0;i<pairs.size();i++){
            unio(pairs[i][0],pairs[i][1],parent);
        }
        
        unordered_map<int,vector<int> > mp;
        for(int i=0;i<parent.size();i++){
            mp[find(i,parent)].push_back(i);
        }
        
        for(auto m:mp){
            string st="";
            for(auto v:m.second){
                st+=s[v];
            }
            sort(st.begin(),st.end());
            int j=0;
            for(auto i:m.second){
                s[i]=st[j++];
            }
        }
        return s;
        
    }
};