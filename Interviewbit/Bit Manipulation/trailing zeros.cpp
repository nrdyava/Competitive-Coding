int Solution::solve(int A) {
    int ans = 0;
    int i=0;
    while(i == 0){
        if ((A&1) == 0){
            ans+=1;
            A = A>>1;
        }
        else{
            i=1;
        }
    }
    return ans;
}
