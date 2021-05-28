int Solution::minPathSum(vector<vector<int> > &A) {
    int m = A.size();
    int n = A[0].size();
    int sum_mat[A.size()][A[0].size()];
    sum_mat[0][0] = A[0][0];
    
    for (int i=1;i<m;i++) sum_mat[i][0] = sum_mat[i-1][0]+A[i][0];
    for (int i=1;i<n;i++) sum_mat[0][i] = sum_mat[0][i-1]+A[0][i];
    
    for (int i=1;i<m;i++){
        for (int j=1;j<n;j++){
            sum_mat[i][j] = min(sum_mat[i][j-1],sum_mat[i-1][j])+A[i][j];
        }
    }
    return sum_mat[m-1][n-1];
    
}