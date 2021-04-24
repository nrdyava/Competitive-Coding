int Solution::findMinXor(vector<int> &A) {
    int ans = INT_MAX;
    int temp=0;
    sort(A.begin(), A.end());
    for (int i=0;i<A.size()-1;i++){
        temp = A[i]^A[i+1];
        ans = min(temp, ans);
    }
    return ans;
}