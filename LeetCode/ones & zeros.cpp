class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(auto it:strs){
            string s=it;
            int cnt_1=0;
            for(int i=0;i<s.size();i++){
                if(s[i]=='1')
                {
                    cnt_1++;
                }
            }
            int cnt_0=s.size()-cnt_1;
            
            for(int i=m;i>=cnt_0;i--){
                for(int j=n;j>=cnt_1;j--){
                    dp[i][j]=max(dp[i][j],dp[i-cnt_0][j-cnt_1]+1);
                }
            }
        }
        return dp[m][n];
    }
};