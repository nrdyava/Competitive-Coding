string Solution::solve(string A) {
    stringstream ss(A);
    string temp;

    A = "";

    while(ss >> temp){
        A = temp + " " + A;
    }
    A.pop_back();
    return A;
}
