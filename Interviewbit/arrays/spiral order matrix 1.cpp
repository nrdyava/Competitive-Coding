vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    int m = A.size();
    int n = A[0].size();
    int t = 0;int b = m-1;int l = 0;int r = n-1;
    vector<int> ans;
    int dir = 0;
    
    while(t<=b && l<=r){
        if (dir == 0){
            for (int i = l; i<=r; i++){
                ans.push_back(A[t][i]);
            }
            t++;
            dir = 1;
        }
        
        else if (dir == 1){
            for (int i = t; i<=b; i++){
                ans.push_back(A[i][r]);
            }
            r--;
            dir = 2;
        }
        
        else if (dir == 2){
            for (int i = r; i>=l; i--){
                ans.push_back(A[b][i]);
            }
            b--;
            dir = 3;
        }
        
        else if (dir == 3){
            for (int i = b; i>=t; i--){
                ans.push_back(A[i][l]);
            }
            l++;
            dir = 0;
        }
        else break;
    }
    return ans;
}
