int Solution::minimumTotal(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int m = A.size();

    if(m == 1) return A[0][0];

    A[1][0] += A[0][0];
    A[1][1] += A[0][0];

    if(m == 2) return min(A[1][0], A[1][1]);

    for(int i=2; i<m; i++){
        A[i][0] += A[i-1][0];
        A[i][i] += A[i-1][i-1]; 
    }

    for(int i=2; i<m; i++){
        for(int j=1; j<=i-1; j++){
            A[i][j] += min(A[i-1][j-1], A[i-1][j]);
        }
    }

    int ans = INT_MAX;

    for(int i=0; i<m; i++){
        ans = min(ans, A[m-1][i]);
    }
    return ans;
}
