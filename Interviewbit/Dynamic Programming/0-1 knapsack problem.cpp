int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int n = A.size();
    int M[n+1][C+1];

    for(int j=0; j<=C; j++){
        M[0][j] = 0;
    }

    for(int i = 1; i<=n; i++){
        for(int j=0; j<=C; j++){
            if(B[i-1] > j) M[i][j] = M[i-1][j];

            else{
                M[i][j] = max(M[i-1][j], A[i-1] + M[i-1][j-B[i-1]]);
            }
        }
    }
    return M[n][C];
}
