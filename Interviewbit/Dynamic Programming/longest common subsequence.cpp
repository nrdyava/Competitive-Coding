int Solution::solve(string A, string B) {
    int m = A.length();
    int n = B.length();
    
    int arr[m+1][n+1];
    for (int i=0;i<=m;i++){
        for (int j=0;j<=n;j++){
            if (i==0 || j==0) arr[i][j]=0;
            else if (A[i-1] == B[j-1]) arr[i][j] = arr[i-1][j-1]+1;
            else arr[i][j] = max(arr[i][j-1], arr[i-1][j]);
        }
    }
    return arr[m][n];
}