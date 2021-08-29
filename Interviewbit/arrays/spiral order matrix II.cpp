vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int>> M(A, vector<int>(A));

    int filler = 1;
    int left = 0;
    int right = A-1;
    int top = 0;
    int bottom = A-1;
    int flag = 1;

    while(left <= right && top <= bottom){
        if(flag == 1){
            for(int i=left; i<=right; i++){
                M[top][i] = filler;
                filler++;
            }
            flag = 2;
            top++;
        }
        else if(flag == 2){
            for(int i=top; i<=bottom; i++){
                M[i][right] = filler;
                filler++;
            }
            flag = 3;
            right--;
        }
        else if(flag == 3){
            for(int i=right; i>=left; i--){
                M[bottom][i] = filler;
                filler++;
            }
            flag = 4;
            bottom--;
        }
        else if(flag == 4){
            for(int i=bottom; i>=top; i--){
                M[i][left] = filler;
                filler++;
            }
            flag = 1;
            left++;
        }
    }
    return M;
}
