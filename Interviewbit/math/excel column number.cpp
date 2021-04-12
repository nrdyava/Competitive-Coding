int Solution::titleToNumber(string A) {
    int n = A.size();
    int ref = 'A';
    int coln = 0;
    for (int i=0; i<n; i++){
        coln*=26;
        coln = coln + int(A[i]) - ref+ 1;
    }
    return coln;
}
