void solver(int v, int psum, int &C, vector<int> &visited, vector<int> &A, unordered_map<int, vector<int>> &M, int &count){
    visited[v] = 1;
    psum = psum + A[v-1];

    for(auto child: M[v]){
        if(visited[child] == 0){
            solver(child, psum, C, visited, A, M, count);
        }
    }

    if(M[v].size() == 1 && psum <= C) count++;
}

int Solution::solve(vector<int> &A, vector<vector<int> > &B, int C) {
    unordered_map<int, vector<int>> M;

    for(int i=0; i<B.size(); i++){
        M[B[i][0]].push_back(B[i][1]);
        M[B[i][1]].push_back(B[i][0]);
    }

    int psum = 0;
    int count = 0;

    vector<int> visited(A.size() + 1, 0);

    solver(1, psum, C, visited, A, M, count);

    return count;
}
