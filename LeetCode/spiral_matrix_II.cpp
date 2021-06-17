class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int s = 1, key = 0;
        int left = 0, right = n-1, top = 0, bottom = n-1;
        vector<vector<int>> matrix(n, vector<int>(n));
        
        while(top <= bottom && left <= right){
            if (key == 0){
                for(int i=left;i<=right; i++){
                    matrix[top][i] = s;
                    s++;
                }
                top+=1;
                key = 1;
            }
            
            else if (key == 1){
                for(int i=top;i<=bottom; i++){
                    matrix[i][right] = s;
                    s++;
                }
                right-=1;
                key = 2;
            }
            
            else if (key == 2){
                for(int i=right;i>=left; i--){
                    matrix[bottom][i] = s;
                    s++;
                }
                bottom-=1;
                key = 3;
            }
            else if (key == 3){
                for(int i=bottom;i>=top; i--){
                    matrix[i][left] = s;
                    s++;
                }
                left+=1;
                key = 0;
            }
        }
        return matrix;
    }
};