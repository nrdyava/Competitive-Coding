bool isvowel(char C){
    return (C == 'a' || C == 'e' || C == 'i' || C == 'o' || C == 'u'); 
}

int Solution::solve(string A) {

    if(A.length() == 0 || A.length() == 1) return 0;

    int vows = 0;
    int cons = 0;

    for(int i=0; i<A.length(); i++){
        if(isvowel(A[i])) vows++;
        else cons++;
    }

    int ans = 0;

    for(int i=0; i<A.length(); i++){
        if(isvowel(A[i])){
            vows--;
            ans = (ans + cons)%1000000007;
        }
        else{
            cons--;
            ans = (ans + vows)%1000000007;
        }
    }
    return ans;
}
