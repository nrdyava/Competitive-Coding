vector<vector<int> > Solution::prettyPrint(int A) {
    int side = 2*A-1;
    int minn = 0;
    vector<vector<int> > ans(side,vector<int>(side));
    
    
    while(A>0){
        for (int i=minn;i<side;i++){
            for(int j=minn;j<side;j++){
                ans[i][j] = A;
            }
        }
        A--;
        side--;
        minn++;
        
    }
    return ans;
}
