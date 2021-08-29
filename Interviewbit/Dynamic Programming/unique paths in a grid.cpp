int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    int m=A.size();
    int n=A[0].size();

    int M[m][n];
    memset(M, 0, sizeof(M));

    if(A[0][0] == 0) M[0][0] = 1;

    for(int i=1; i<m; i++){
        if(A[i][0] == 0) M[i][0] = M[i-1][0];
    }

    for(int i=1; i<n; i++){
        if(A[0][i] == 0) M[0][i] = M[0][i-1];
    }

    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(A[i][j] == 0) M[i][j] = M[i][j-1] + M[i-1][j];
        }
    }

    return M[m-1][n-1];
}
