class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();
        int lookup[m+1][n+1];
        memset(lookup, 0, sizeof(lookup));
        
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(str1[i-1] == str2[j-1]) lookup[i][j] = lookup[i-1][j-1] + 1;
                else lookup[i][j] = max(lookup[i][j-1], lookup[i-1][j]);
            }
        }
        
        string scs = "";
        
        int i=m;
        int j=n;
        
        while(i>0 && j>0){
            if(str1[i-1] == str2[j-1]){
                scs.push_back(str1[i-1]);
                i--;
                j--;
            }
            else if(lookup[i][j-1] < lookup[i-1][j]){
                scs.push_back(str1[i-1]);
                i--;
            }
            else{
                scs.push_back(str2[j-1]);
                j--;
            }
        }
        
        while(i>0){
            scs.push_back(str1[i-1]);
            i--;
        }
        
        while(j>0){
            scs.push_back(str2[j-1]);
            j--;
        }
        
        reverse(scs.begin(), scs.end());
        return scs;
    }
};