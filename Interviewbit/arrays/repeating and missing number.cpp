vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long int n = A.size();
    long long int S = n*(n+1)/2;
    long long int S2 = n*(n+1)*(2*n+1)/6;

    long long int rep, miss;

    for(int i=0; i<n; i++){
        S = S - (long long int)A[i];
        S2 = S2 - (long long int)A[i] * (long long int)A[i];
    }

    miss = (S + (S2/S))/2;
    rep = miss - S;

    vector<int> ans;
    ans.push_back(rep);
    ans.push_back(miss); 
    return ans;
}
