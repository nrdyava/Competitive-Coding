class Solution {
public:
    int searchForRow(vector<vector<int>>& matrix, int target){
        int t=0, b=matrix.size()-1, mid, row= -1;
        
        while(t<=b){
            mid = (t+b)/2;
            if(matrix[mid][0] <= target){
                t = mid + 1;
                row = mid;
            }
            else b = mid - 1;
        }
        
        return row;
    }
    
    bool searchInRow(vector<vector<int>>& matrix, int target,int row){
        int left, right, mid;
        left = 0;
        right = matrix[0].size() - 1;
        
        while(left <= right){
            mid = (left+right)/2;
            if (matrix[row][mid] == target)  return true;
            else if(matrix[row][mid] < target) left = mid+1;
            else right = mid - 1;
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = searchForRow(matrix, target);
        if (row == -1) return false;
        return searchInRow(matrix, target, row);
    }
};