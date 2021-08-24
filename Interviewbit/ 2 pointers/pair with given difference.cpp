int Solution::solve(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    int n = A.size();

    int i = 0;
    int j = 0;

    while(i < n && j < n){
        if(A[j] - A[i] == B && i!=j) return 1;
        if(A[j] - A[i] < B) j++;
        else i++;
    }
    return 0;
}
