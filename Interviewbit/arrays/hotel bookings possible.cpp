bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    int n = arrive.size();
    vector<pair<int, int>> p;

    for(int i=0; i<n; i++) p.push_back({arrive[i], 1});
    for(int i=0; i<n; i++) p.push_back({depart[i], 0});

    sort(p.begin(), p.end());

    int count = 0;

    for(int i=0; i<2*n; i++){
        if(p[i].second == 1) count++;
        else count--;

        if(count > K) return 0;
    }
    return 1;
}
