int Solution::solve(vector<int> &A, int B) {

    int n = A.size();

    int ans = 0;
    int flag;

    for(int i=0; i<n; i++){
        flag = 0;
        for(int j=i+B-1; j>=i-B+1; j--){
            if(j>=0 && j<n && A[j]==1){
                flag = 1;
                i = j+B-1;
                ans++;
                break;
            }
        }
        if(flag == 0) return -1;
    }
    return ans;
}