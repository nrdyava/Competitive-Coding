bool dfs_util(int A, vector<int> &visited, vector<int> &recStack, map<int, vector<int>> &M){
    visited[A] = 1;
    recStack[A] = 1;

    for(auto child: M[A]){
        if(recStack[child] == 1) return true;
        else if(!visited[child] && dfs_util(child, visited, recStack, M)) return true;
    }
    recStack[A] = 0;
    return false;
}


int Solution::solve(int A, vector<vector<int> > &B) {
    map<int, vector<int>> M;

    for(int i=0; i<B.size(); i++){
        M[B[i][0]].push_back(B[i][1]);
    }

    vector<int> recStack(A+1, 0);
    vector<int> visited(A+1, 0);

    for(int i=1; i<=A; i++){
        if(!visited[i] && dfs_util(i, visited, recStack, M)) return true;
    }

    return false;
}
