int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int maxm = INT_MIN;
    int temp = 0;
    int j=1;

    for(int i=0; i<B; i++){
        temp += A[i];
    }

    for(int i=B-1; i >= 0; i--){
        temp = temp - A[i] + A[n-j];
        maxm = max(maxm, temp);
        j++;
    }

    return maxm;
}
