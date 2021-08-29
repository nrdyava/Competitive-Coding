void subsets_util(vector<int> &A, vector<int> subset, vector<vector<int>> &ans, int index){
    ans.push_back(subset);
    for(int i = index; i<A.size(); i++){
        subset.push_back(A[i]);

        subsets_util(A, subset, ans, i+1);

        subset.pop_back();
    }
    return;
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    sort(A.begin(), A.end());
    vector<vector<int>> ans;
    vector<int> subset;
    int index = 0;

    subsets_util(A, subset, ans, index);
    return ans;
}
