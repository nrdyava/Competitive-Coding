int Solution::uniquePaths(int A, int B) {
    if (A == 0 || B ==0){
        return 0;
    }
    
    if (A ==1 || B == 1){
        return 1;
    }
    
    int matrix[A+1][B+1];
    
    for (int i = 1; i<=A; i++){
        matrix[i][B] = 1;
    }
    
    for (int i = 1; i<=B ;i++){
        matrix[A][i] = 1;
    }
    
    for (int j = B-1; j>=1; j--) {
        for (int i = A-1;i>=1;i--){
            matrix[i][j] = matrix[i+1][j] + matrix[i][j+1];
        }
    }
    
    return matrix[1][1];
    
}