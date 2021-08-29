bool dfs_util(int A, vector<int> &visited, int parent,unordered_map<int, vector<int>> &M){
    visited[A] = 1;

    for(int i=0; i < M[A].size(); i++){
        if(M[A][i] != parent && visited[M[A][i]]) return true;
        if (!visited[M[A][i]] && dfs_util(M[A][i], visited, A, M)) return true;
    }

    return false;
}

int Solution::solve(int A, vector<vector<int> > &B) {

    if(B.size() == 0 || B.size() == 1 || B.size() == 2) return 0;

    unordered_map<int, vector<int>> M;
    for(int i=0; i<B.size(); i++){
        M[B[i][0]].push_back(B[i][1]);
        M[B[i][1]].push_back(B[i][0]); 
    }

    vector<int> visited(A+1, 0);

    for(int i=1; i<=A; i++){
        if(!visited[i] && dfs_util(i, visited, -1, M)) return 1;
    }

    return 0;
}
