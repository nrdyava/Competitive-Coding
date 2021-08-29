int Solution::solve(int A, vector<vector<int> > &B) {
    map<int, vector<int>> M;

    for(int i=0; i<B.size(); i++) M[B[i][0]].push_back(B[i][1]);

    vector<int> vis(A+1, 0);

    stack<int> s;
    s.push(1);
   

    int curr;

    while(!s.empty()){
        curr = s.top();
        s.pop();

        vis[curr] = 1;

        if(curr == A) return 1;

        if(M.find(curr) != M.end()){
            for(auto x: M[curr]){
                if(vis[x] == 0){
                    s.push(x);
                }
            }
        }
    }

    return 0;
}
