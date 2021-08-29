int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    int M[n][m];
    int maxxs = -1;

    for(int i=0; i<n; i++) M[i][0] = A[i][0];
    for(int i=0; i<m; i++) M[0][i] = A[0][i];

    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(A[i][j] == 1){
                M[i][j] = 1 + min(M[i-1][j-1], min(M[i][j-1], M[i-1][j]));
            }
            else M[i][j] = 0;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            maxxs = max(maxxs, M[i][j]);
        }
    }

    return maxxs*maxxs;
}
