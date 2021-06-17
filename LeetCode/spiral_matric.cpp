class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> spiral;
        int left, right, top, bottom, key;
        key = 0;
        left = 0;
        right = matrix[0].size() - 1;
        top = 0;
        bottom = matrix.size()-1;
        
        while(left <= right && top <= bottom){
            if (key == 0) {
                for(int i=left; i<=right; i++) spiral.push_back(matrix[top][i]); top++;key=1;
            }
            else if (key == 1){
                for(int i=top; i<=bottom; i++) spiral.push_back(matrix[i][right]); right--;key=2;
            }
            else if (key == 2){
                for(int i=right; i>=left; i--) spiral.push_back(matrix[bottom][i]); bottom--;key=3;
            }
            else if (key == 3){
                for(int i=bottom; i>=top; i--) spiral.push_back(matrix[i][left]); left++;key=0;
            }
            
        }
        return spiral;
    }
};