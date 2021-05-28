int Solution::lis(const vector<int> &A) {
    int n = A.size();
    int lis_arr[n];
    
    lis_arr[0]=1;
    for (int i=1;i<n;i++){
        lis_arr[i] = 1;
        for (int j=0;j<i;j++){
            if (A[j]<A[i]){
                lis_arr[i] = max(lis_arr[i], lis_arr[j]+1);
            }
        }
    }
    return *max_element(lis_arr, lis_arr+n);
}