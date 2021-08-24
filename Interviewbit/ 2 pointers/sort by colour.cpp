void Solution::sortColors(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    int pos = 0;
    for(int i=0; i<n; i++){
        if(A[i]==0) swap(A[i], A[pos++]);
    }
    pos = n-1;
    for(int i = n-1; i>=0; i--){
        if(A[i] == 2) swap(A[i], A[pos--]);
    }
}
