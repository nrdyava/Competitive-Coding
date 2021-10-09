class Solution {
    bool isvalid(int i, int j, int m, int n){
        if(i>=0 && i<m && j>=0 && j<n) return true;
        else return false;
    }
    
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        int onecnt;
        
        int x[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int y[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                onecnt = 0;
                for(int k=0; k<8; k++){
                    if(isvalid(i+x[k], j+y[k], m,  n)) onecnt = onecnt + board[i+x[k]][j+y[k]]%2;
                }
                
                if(board[i][j] == 0){
                    if(onecnt == 3) board[i][j] += 2*1;
                }
                
                else{
                    if(onecnt < 2) board[i][j] += 2*0;
                    else if(onecnt == 2 || onecnt == 3) board[i][j] += 2*1;
                    else board[i][j] += 2*0; 
                }
            }
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                board[i][j] = board[i][j]/2;
            }
        }
    }
};
