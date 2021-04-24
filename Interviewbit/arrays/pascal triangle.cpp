vector<vector<int> > Solution::solve(int A) {
    vector<vector<int>> ans;
    vector<int> k;
    
    if (A == 0){
        return ans;
    }
    
    k.push_back(1);
    ans.push_back(k);
    
    for(int i = 1; i<= A-1;i++){
        vector<int> row;
        row.push_back(1);
        int l =1;
        for(int j=1; j<=i; j++){
            row.push_back(l*(i-j+1)/j);
            l = row[j];
        }
        ans.push_back(row);
    }
    return ans;
}
