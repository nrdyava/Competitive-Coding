string Solution::largestNumber(const vector<int> &A) {
    int n = A.size();
    vector<string> B;

    for(int i=0; i<n; i++){
        B.push_back(to_string(A[i]));
    }

    sort(B.begin(), B.end(), [](string x, string y)->bool{return x+y > y+x;});
    string ans = "";

    for(int i=0; i<n;i++){
        ans += B[i];
    }
    
    if(B[0] == "0") return "0";
    return ans;
}
