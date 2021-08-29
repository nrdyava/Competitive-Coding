int Solution::numTrees(int A) {
    vector<long long int> dp(A+1, 0);
    dp[0] = 1;
    dp[1] = 1;

    if(A == 1) return dp[A];

    for(int i=2; i<=A; i++){
        for(int j=1; j<=i; j++){
            dp[i] += dp[j-1] * dp[i-j];
        }
    }

    return dp[A];
}
