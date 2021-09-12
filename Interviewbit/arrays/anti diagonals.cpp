vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int n = A.size();

    int i, j;

    vector<vector<int>> ans;

    if(n == 0) return ans;

    if(n==1){
        vector<int> temp;
        temp.push_back(A[0][0]);
        ans.push_back(temp);
        return ans;
    }

    for(int k=0; k<n-1; k++){
        vector<int> temp;
        i = 0;

        for(j = k; j>=0; j--, i++){
            temp.push_back(A[i][j]);
        }
        ans.push_back(temp);
    }

    vector<int> temp;
    for(int k=0; k<=n-1; k++){
        temp.push_back(A[k][n-k-1]);
    }
    ans.push_back(temp);

    for(int k=1; k<=n-1; k++){
        vector<int> temp;
        j = n-1;

        for(i = k; i<=n-1; j--, i++){
            temp.push_back(A[i][j]);
        }
        ans.push_back(temp);
    }

    return ans;
}
