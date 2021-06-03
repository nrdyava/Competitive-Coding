class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m==1 || n==1) return 1;
        int uparray[m+1][n+1];
        for (int i=1;i<n+1;i++) uparray[1][i] = 1;
        for (int i=1;i<m+1;i++) uparray[i][1] = 1;
        for (int i=2;i<m+1;i++){
            for (int j=2;j<n+1;j++){
                uparray[i][j] = uparray[i][j-1] + uparray[i-1][j];
            }
        }
        return uparray[m][n];
    }
};