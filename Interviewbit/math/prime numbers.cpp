vector<int> Solution::sieve(int A) {
    bool prime[A+1];
    memset(prime, 1, sizeof(prime));
    
    vector<int> ans;
    
    if (A <= 1) {
        return ans;
    }
    
    for (int i = 2; i*i <= A; i++){
        if (prime[i] == 1) {
            for (int j = i*i; j<=A; j+=i) {
                prime[j] = 0;
            }
        }
    }
    
    for (int i = 2; i<= A; i++){
        if (prime[i] == 1){
            ans.push_back(i);
        }
    }
    return ans;
}