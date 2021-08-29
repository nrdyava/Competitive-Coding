int Solution::lengthOfLastWord(const string A) {
    stringstream ss(A);

    string temp;

    while(ss >> temp){
        continue;
    }
    return temp.length();
}
