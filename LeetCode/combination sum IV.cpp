class Solution {
public:
    int dp[20002];
    int combinationSum4(vector<int>& nums, int target) {
        int s = nums.size();
        sort(nums.begin(),nums.end());
        memset(dp,-1,sizeof(dp));
        return fun(nums,s,0,target);
    }
    int fun(vector<int>& nums,int n,int sum,int target) {
        
        if(sum>target)
            return 0;
        if(sum == target)
            return 1;
        if(dp[sum] != -1)
            return dp[sum];
        int res = 0;
        for(int ind=0;ind<n;ind++) {
            res += fun(nums,n,nums[ind]+sum,target);
        }
        return dp[sum] = res;
    }
};
