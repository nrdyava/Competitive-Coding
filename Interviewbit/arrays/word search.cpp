class Solution {
public:
    int vis[1000][1000];
    bool flag=false; 
    
    void dfs(vector<vector<char>>& board, int i, int j, string word, int wordIdx){
        int m=board.size(), n=board[0].size();
        
        vis[i][j]=1;
    
        if(wordIdx==word.length()-1 && word[wordIdx]==board[i][j]){
            flag=1;
            return;
        }
        
        wordIdx++;
        if(i+1<m && i+1>=0 && j<n && j>=0 && vis[i+1][j]!=1 && word[wordIdx]==board[i+1][j]){
            dfs(board, i+1, j, word, wordIdx);
        } if(i-1<m && i-1>=0 && j<n && j>=0 && vis[i-1][j]!=1 && word[wordIdx]==board[i-1][j]){
            dfs(board, i-1, j, word, wordIdx);
        } if(i<m && i>=0 && j+1<n && j+1>=0 && vis[i][j+1]!=1 && word[wordIdx]==board[i][j+1]){
            dfs(board, i, j+1, word, wordIdx);
        } if(i<m && i>=0 && j-1<n && j-1>=0 && vis[i][j-1]!=1 && word[wordIdx]==board[i][j-1]){
            dfs(board, i, j-1, word, wordIdx);
        }
        vis[i][j]=0;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(), n=board[0].size();
        
        bool ans=false;
        
        memset(vis, 0, sizeof(vis));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                flag=false;
                if(board[i][j]==word[0]){
                    memset(vis, 0, sizeof(vis));
                    vis[i][j]=1;
                    dfs(board, i, j, word, 0);
                }
                if(flag==true){
                    return flag;
                }
            }
        }
        return flag;
    }
};