int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int M[n+1][n+1];
    memset(M, 0, sizeof(M));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            M[i][j] = A[i-1][j-1] + max(M[i-1][j-1], M[i-1][j]);
        }
    }
    int ans = INT_MIN;

    for(int i=1; i<=n; i++){
        ans = max(ans, M[n][i]);
    }
    return ans;
}
