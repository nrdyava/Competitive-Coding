vector<int> bfs_util(int start, int n, unordered_map<int,  vector<int>> &M){
    vector<int> visited(n, 0);
    
    int m;
    int curr;
    int last_node;
    int k=0;

    vector<int> ans;
    queue<int> q;

    q.push(start);

    while(!q.empty()){
        m = q.size();

        while(m--){
            curr = q.front();
            visited[curr] = 1;

            for(auto x: M[curr]){
                if(!visited[x]){
                    q.push(x);
                    last_node = x;
                    }
            }
            q.pop();
        }
        k++;
    }
    ans.push_back(last_node);
    ans.push_back(k-1);
    return ans;
}


int Solution::solve(vector<int> &A) {
    int n = A.size();
    unordered_map<int,  vector<int>> M;

    for(int i=0; i<n; i++){
        if(A[i] == -1) continue;
        M[i].push_back(A[i]);
        M[A[i]].push_back(i);
    }

    if(n == 0 || n == 1) return 0;
    int start = 0;

    vector<int> bfs1 = bfs_util(start, n, M);
    bfs1 = bfs_util(bfs1[0], n, M);
    return bfs1[1];
}
