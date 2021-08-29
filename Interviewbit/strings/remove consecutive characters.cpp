string Solution::solve(string A, int B) {
int s = 0, e = 0;
string res="";
while(s<A.length()){
    e=s;
    while(A[e]==A[e+1] && e<A.length()) e++;
    if(e-s+1!=B) res+=A.substr(s, e-s+1);
    s=e+1;
}
return res;
}