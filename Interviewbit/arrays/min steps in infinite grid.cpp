int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int np = A.size();
    int dx = 0; int dy = 0;
    int steps = 0;
    
    for (int i = 1; i<np; i++){
        dx=abs(A[i]-A[i-1]);
        dy=abs(B[i]-B[i-1]);
        steps+=max(dx,dy);
    }
    return steps;
}