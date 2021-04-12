string Solution::findDigitsInBinary(int A) {
    if (A == 0){
        return "0";
    }
    if (A == 1){
        return "1";
    }
    string ans;
    int i = A;
    while(i!=1){
        if (i%2 == 0){
            ans += "0";
        } else{
            ans += "1";
        }
        i = i/2;
    }
    ans += "1";
    reverse(ans.begin(), ans.end());
    return ans;
}
