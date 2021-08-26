int Solution::numDistinct(string A, string B) {
int a=A.size();
int b=B.size();

vector<vector<int> >dp(a+1,vector<int>(b+1));

for(int j=0;j<=b;j++){
    dp[0][j]=0;
}

for(int i=0;i<=a;i++)
{
    dp[i][0]=1;
}

for(int i=1;i<=a;i++)
{
    for(int j=1;j<=b;j++)
    {
        if(A[i-1]==B[j-1]){
            dp[i][j] = (dp[i-1][j]+dp[i-1][j-1]);
        }
        else
        dp[i][j]=dp[i-1][j];
    }
}
return dp[a][b];
}