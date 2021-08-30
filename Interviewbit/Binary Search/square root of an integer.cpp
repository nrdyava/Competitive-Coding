int Solution::sqrt(int A) {
    if(A == 0 || A == 1) return A;
    int start = 1, end = A, mid;
    int ans;

    while(start <= end){
        mid = start + (end - start)/2;

        if(mid*mid == A) return mid;

        if(mid <= A/mid){
            start = mid + 1;
            ans = mid;
        } 
        else end = mid - 1;
    }
    return ans;
}
