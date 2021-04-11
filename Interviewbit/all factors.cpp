vector<int> Solution::allFactors(int A) {
    vector<int> ans{1};
    for (int i = 2;i<=floor(sqrt(A));i++){
        if (A%i == 0){
            ans.push_back(i);    
        }
    }
    
    if (sqrt(A) == floor(sqrt(A))){
        ans.pop_back();
    }
    for (int i = floor(sqrt(A)); i>=2;i--){
        if (A%i == 0){
            ans.push_back(A/i);
        }
    }
    return ans;
}