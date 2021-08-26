bool isscrmbl(string A, string B, unordered_map<string, bool> &M){
    if(A.length()!= B.length()) return false;

    int n = A.length();

    if(n == 0) return true;

    if(A == B) return true;

    string copy1 = A;
    string copy2 = B;

    sort(copy1.begin(), copy1.end());
    sort(copy2.begin(), copy2.end());

    if(copy1 != copy2) return false;

    string key = A + " " + B;

    if(M.find(key) != M.end()) return M[key];

    for(int i=1; i<n; i++){
        if(isscrmbl(A.substr(0, i), B.substr(0, i), M) && isscrmbl(A.substr(i, n-i), B.substr(i, n-i), M)){
            return true;
        }
    }

    for(int i=1; i<n; i++){
        if(isscrmbl(A.substr(0, i), B.substr(n-i, i), M) && isscrmbl(A.substr(i, n-i), B.substr(0, n-i), M)){
            return true;
        }
    }

    M[key] = false;
    return false;

}

int Solution::isScramble(const string A, const string B) {
    unordered_map<string, bool> M;
    
    if(isscrmbl(A, B, M)) return 1;
    return 0;

}
