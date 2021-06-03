class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int dmat[r][c];
        
        for (int i=0;i<r;i++) dmat[i][0] = ((int)matrix[i][0]) - '0';
        for (int i=0;i<c;i++) dmat[0][i] = ((int)matrix[0][i]) - '0';
        
        for (int i=1;i<r;i++){
            for(int j=1;j<c;j++){
                if (matrix[i][j] == '1'){
                    dmat[i][j] = 1 + min({dmat[i-1][j], dmat[i][j-1], dmat[i-1][j-1]});
                }
                else dmat[i][j] = 0;
            }
        }
        int maxe = INT_MIN;
        for (int i=0; i<r;i++){
            for(int j=0; j<c; j++){
                maxe = max(maxe, dmat[i][j]);
            }
        }
        return maxe*maxe;
    }
};