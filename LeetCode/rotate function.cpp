class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int ans = INT_MIN;
        int f=0;
        
        for(int i=0; i<n; i++) sum = sum + nums[i], f += i*nums[i];
        for(int i=0; i<n; i++) f += n*nums[i] - sum, ans = max(ans, f);
        
        return ans;
    }
};