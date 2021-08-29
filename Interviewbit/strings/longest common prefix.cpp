string lcp(string &A, string &B){
    int n1 = A.length();
    int n2 = B.length();

    string result;
    for(int i=0, j=0; i<n1 && j<n2; i++, j++){
        if(A[i] != B[j]){
            break;
        }
        result.push_back(A[i]);
    }
    return result;
}

string Solution::longestCommonPrefix(vector<string> &A) {
    string result = A[0];

    for(int i=1; i< A.size(); i++){
        result = lcp(result, A[i]);
    }

    return result;
}
