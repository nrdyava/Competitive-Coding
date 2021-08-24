int Solution::maxProfit(const vector<int> &A) {
    int n = A.size();
    if(n == 0 || n==1) return 0;
    int j = 1;
    
    int maxp = 0;

    for(int j=1; j<n; j++){
        maxp += max(A[j] - A[j-1], 0);
    }
    return maxp;
}
