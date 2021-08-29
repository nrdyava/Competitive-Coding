int Solution::coinchange2(vector<int> &A, int B) {
    int m = A.size();
    int DP[B+1];
    memset(DP, 0, sizeof(DP));

    DP[0] = 1;

    for(int i=0; i<m; i++){
        for(int j=A[i]; j<=B; j++){
            DP[j] = (DP[j] + DP[j-A[i]])%1000007;
        }
    }
    return DP[B];
}
