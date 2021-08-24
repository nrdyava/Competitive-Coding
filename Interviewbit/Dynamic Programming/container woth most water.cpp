int Solution::maxArea(vector<int> &A) {
    int n = A.size();
    int left = 0;
    int right = n-1;
    int mx = 0;

    while(left <= right){
        mx = max(mx, min(A[left], A[right]) * (right - left));
        if(A[left] <= A[right]) left++;
        else right--;
    }
    
    return mx;
}
