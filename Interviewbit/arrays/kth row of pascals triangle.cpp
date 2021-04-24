vector<int> Solution::getRow(int A) {
    vector<int> ans;
    if (A == 0){
        ans.push_back(1);
        return ans;
    }
    
    ans.push_back(1);
    int k = 1;
    for (int i = 1; i<=A; i++){
        ans.push_back((k*(A-i+1))/i);
        k = ans[i];
    }
    return ans;
    
}
