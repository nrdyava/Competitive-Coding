void permutations(vector<int> A, int left, int right, vector<vector<int>> &ans){
    if(left == right) ans.push_back(A);

    for(int i=left; i<=right; i++){
        swap(A[left], A[i]);
        permutations(A, left+1, right, ans);
        swap(A[left], A[i]);
    }
}

vector<vector<int>> Solution::permute(vector<int> &A) {
    int n = A.size();
    vector<vector<int>> ans;
    permutations(A, 0, n-1, ans);

    return ans;
}
