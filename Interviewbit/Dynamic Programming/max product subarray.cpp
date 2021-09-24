int Solution::maxProduct(const vector<int> &A) {
    int n = A.size();
    int max_ending_here, min_ending_here, maxp;
    int temp;

    max_ending_here = A[0];
    min_ending_here = A[0];
    maxp = A[0];

    for(int i=1; i<n; i++){
        temp = max_ending_here;

        max_ending_here = max(A[i], max(A[i]*max_ending_here, A[i]*min_ending_here));
        min_ending_here = min(A[i], min(temp*A[i], A[i]*min_ending_here));

        maxp = max(maxp, max_ending_here);
    }

    return maxp;

}
