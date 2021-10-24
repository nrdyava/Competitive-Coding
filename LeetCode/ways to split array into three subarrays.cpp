class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int sum=0;
        
        vector<int>pre(nums.size(),0);
        
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            pre[i]=sum;
        }
        
        long long int ans=0,left,rem,a,b,k=0;
        for(int i=0;i<nums.size();i++)
        {
          left=pre[i];
          rem=pre[nums.size()-1]-left;
          a=lower_bound(pre.begin()+i+1,pre.end(),2*left)-pre.begin();
          b=upper_bound(pre.begin()+i+1,pre.begin()+nums.size()-1,left+rem/2)-pre.begin();
            
            ans+=max(k,(b-a));
        }
        return ans%1000000007;
    }
};