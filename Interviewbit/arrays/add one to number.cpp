vector<int> Solution::plusOne(vector<int> &A) {
    int carry = 0;
    int n = A.size();

    A[n-1] = A[n-1]+1;
    carry = A[n-1]/10;
    A[n-1] = A[n-1]%10;

    for(int i=n-2; i>=0; i--){
       if(carry == 1){
           A[i] = A[i] + carry;
           carry = A[i]/10;
           A[i] = A[i]%10;
       }

    }

    if(carry == 1){
        A.insert(A.begin(), 1);
    }

    while(1){
        if(A[0] != 0) break;
        A.erase(A.begin());
    }

    return A;
}
