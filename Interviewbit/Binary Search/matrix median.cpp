int Solution::findMedian(vector<vector<int> > &A) {
    int maxx = INT_MIN;
    int minn = INT_MAX;

    int n = A.size();
    int m = A[0].size();

    for(int i=0; i<n; i++){
        maxx = max(maxx, A[i][m-1]);
        minn = min(minn, A[i][0]);
    }

    int balance = (n*m + 1)/2;

    while(minn < maxx){
        int mid = minn + (maxx - minn)/2;

        int nbalance = 0;
        for(int i = 0; i<n; i++){
            nbalance = nbalance + (upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin()); 
        }
        if(nbalance < balance) minn = mid + 1;
        else maxx = mid;
    }
    return minn;
}
