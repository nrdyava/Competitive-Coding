vector<int> Solution::primesum(int A) {
    bool primes[A+1];
    memset(primes,1,sizeof(primes));
    vector<int> prms;
    
    for (int i=2; i*i <= A; i++){
        if (primes[i] == 1){
            for (int j = i*i; j<=A; j+=i){
                primes[j] = 0;
            }            
        }
    }
    
    for (int i = 2; i<= A; i++){
        if (primes[i] && primes[A-i]) {
            vector<int> ans;
            ans.push_back(i);
            ans.push_back(A-i);
            return ans;
        }
    }
    
}