int Solution::maxProfit(const vector<int> &A) {
    int n = A.size();
    if(n ==0 || n==1) return 0;
    if(n == 2) return max(0, A[1] - A[0]);

    int mn = A[0];
    int mx = A[n-1];

    int dpl[n];
    int dpr[n];
    
    memset(dpl, 0, sizeof(dpl));
    memset(dpr, 0, sizeof(dpr));

    for(int i=1; i<n; i++){
        if(A[i] < mn) mn = A[i];
        dpl[i] = max(dpl[i-1], A[i] - mn);
    }

    for(int i=n-2; i>=0; i--){
        if(A[i] > mx) mx = A[i];
        dpr[i] = max(dpr[i+1], mx - A[i]);
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        ans = max(ans, dpl[i] + dpr[i]);
    }
    return ans;
}
