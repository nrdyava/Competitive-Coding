vector<int> parser(string s, char del){
    string temp = "";
    vector<int> parsed;

    for(int i=0; i<s.length(); i++){
        if(s[i] == del){
            parsed.push_back(to_int(temp));
            temp = "";
        };
        else{
            temp = temp + s[i];
        }
    }

    return parsed;
}

int Solution::compareVersion(string A, string B) {
    vector<int> v1 = parser(A, '.');
    vector<int> v2 = parser(B, '.');

    int n1 = v1.size();
    int n2 = v2.size();
    int n = max(n1, n2);
    int i=0;

    while(i<n){
        int comp1 = (i<n1)?v1[i]:0;
        int comp2 = (i<n2)?v2[i]:0;

        if(comp1 < comp2) return -1;
        else if(comp1 > comp2) return 1;
        i++;
    }
    return 0;
}
