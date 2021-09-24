void solver(string A, vector<string> B, string temp, vector<string> &output){
    if(A.size() == 0){
        output.push_back(temp.substr(1));
        return;
    }

    for(int i=1; i<=A.size(); i++){
        string prefix = A.substr(0, i);
        if(find(B.begin(), B.end(), prefix) != B.end()){
            solver(A.substr(i), B, temp + " " + prefix, output);
        }
    }
}

vector<string> Solution::wordBreak(string A, vector<string> &B) {
    vector<string> output;
    solver(A, B, "", output);
    sort(output.begin(), output.end());
    return output;
}
