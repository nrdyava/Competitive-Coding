int Solution::longestSubsequenceLength(const vector<int> &A) {
    int n = A.size();

    if(n<3) return n;

    int temp;

    int dpfor[n];
    int dpbac[n];

    dpfor[0] = 1;

    for(int i=1; i<n; i++){
        dpfor[i] = 1;
        for(int j=0; j<i; j++){
            if(A[j] < A[i] && dpfor[i] < dpfor[j] + 1) dpfor[i] = dpfor[j]+1;
        }
    }

    dpbac[n-1] = 1;

    for(int i=n-2; i>=0; i--){
        dpbac[i] = 1;
        for(int j=n-1; j>i; j--){
            if(A[j] < A[i] && dpbac[i] < dpbac[j] + 1) dpbac[i] = dpbac[j]+1;
        }
    }

    int ans = 0;

    for(int i=0; i<n; i++){
        ans = max(ans, dpfor[i] + dpbac[i] - 1);
    }

    return ans;
}
