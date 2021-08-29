int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    vector<pair<int, int>> p;

    for(int i=0; i<n; i++) p.push_back({A[i][0], 1});
    for(int i=0; i<n; i++) p.push_back({A[i][1], 0});

    sort(p.begin(), p.end());

    int count = 0;
    int ans = 0;
    for(int i=0; i<2*n; i++){
        if(p[i].second == 1) count++;
        else count--;

        ans = max(count, ans);
    }
    return ans;

}
