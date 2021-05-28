int Solution::climbStairs(int A) {
    if (A==1) return 1;
    if (A==2) return 2;
    
    int arr[A];
    arr[0]=1;
    arr[1]=2;
    
    for (int i=2; i<A;i++){
        arr[i] = arr[i-1]+arr[i-2];
    }
    return arr[A-1];
}