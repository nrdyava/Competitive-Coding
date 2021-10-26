#define ll long long int
class Solution 
{
public:
    int numberOfArithmeticSlices(vector<int>& A) 
    {
        int count=0,i,j;
        vector<map<ll,int>>dp(A.size());
        for(i=1;i<A.size();i++)
        {
            for(j=0;j<i;j++)
            {
                ll diff=(ll)A[i]-(ll)A[j];
                if(dp[j].find(diff)!=dp[j].end())
                {
                    dp[i][diff]+=dp[j][diff]+1;
                    count+=dp[j][diff];
                }
                else
                {
                    dp[i][diff]+=1;
                }
            }
        }
        return count;
    }
};