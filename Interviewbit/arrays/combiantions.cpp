class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        for(int i=0; i<1<<n; i++){
            int temp = i;
            
            int nbits = 0;
            for(int t=0; t<n; t++){
                if(temp & (1<<t)) nbits++;
            }
            
            if(nbits != k) continue;
            
            vector<int> tmp_vec;
            for(int t=0; t<n; t++){
                if(temp & (1<<t)) tmp_vec.push_back(t+1);
            }
            
            ans.push_back(tmp_vec);
        }
        return ans;
    }
};