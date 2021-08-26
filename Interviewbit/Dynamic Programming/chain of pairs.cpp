int Solution::solve(vector<vector<int>> &A)
{
int n = A.size();
if(n==0)
return 0;

int dp[n];

for(int x=0; x<n; x++)
{
    dp[x] = 1;
}
int ans = 1;
for(int x=1; x<n; x++)
{
    int a1 = A[x][0], a2 = A[x][1];
    
    for(int y = x-1; y>=0; y--)
    {
        if(A[y][1]<a1)
        {
            dp[x] = max(dp[y]+1,dp[x]);
        }
    }
    ans = max(dp[x],ans);
}

return ans;
}