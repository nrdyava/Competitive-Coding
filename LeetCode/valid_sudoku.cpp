class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            if(checkRow(board, i)) continue;
            return false;
        }
        
        for(int i=0; i<9; i++){
            if(checkCol(board, i)) continue;
            return false;
        }
        
        for(int i=0; i<9; i=i+3){
            for(int j=0; j<9; j=j+3){
                if(checkBox(board, i, j)) continue;
                return false;
            }
        }
        return true;
    }
    
private:
    bool checkRow(vector<vector<char>>& board, int row){
        vector<bool> marker(10, false);
        for(int i=0; i<9; i++){
            if(board[row][i] != '.'){
                if(marker[board[row][i] - '0'] == true) return false;
                else marker[board[row][i] - '0'] = true;
            }
        }
        return true;
    }
    
    bool checkCol(vector<vector<char>>& board, int col){
        vector<bool> marker(10, false);
        for(int i=0; i<9; i++){
            if(board[i][col] != '.'){
                if(marker[board[i][col] - '0'] == true) return false;
                else marker[board[i][col] - '0'] = true;
            }
        }
        return true;
    }
    
    bool checkBox(vector<vector<char>>& board, int k, int l){
        vector<bool> marker(10, false);
        for(int i=k; i<k+3; i++){
            for(int j=l; j<l+3; j++){
                if(board[i][j] != '.'){
                    if(marker[board[i][j] - '0'] == true) return false;
                    else marker[board[i][j] - '0'] = true;
                }
            }
        }
        return true;
    }
};