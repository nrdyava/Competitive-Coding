int Solution::maxSubArray(const vector<int> &A) {

    int n = A.size();

    long long int max_ending_here = 0;
    long long int max_till_here = INT_MIN;

    for(int i=0; i<n; i++){
        max_ending_here += A[i];
        if(max_till_here < max_ending_here) max_till_here = max_ending_here;
        if(max_ending_here < 0) max_ending_here=0;
    }
    return max_till_here;

}