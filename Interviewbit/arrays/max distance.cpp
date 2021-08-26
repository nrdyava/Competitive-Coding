int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    if(n == 1) return 0;
    vector<pair<int, int>> p;
    for(int i=0; i<n; i++) p.push_back({A[i], i});
    sort(p.begin(), p.end(), [](auto x, auto y)->bool{return x.first < y.first;});

    int min_index = p[0].second;
    int ans = INT_MIN;

    for(int i=1; i<n; i++){
        min_index = min(min_index, p[i].second);
        ans = max(ans, p[i].second - min_index);
    }

    return ans;
}
 