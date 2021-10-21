class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int ans = max_so_far;
        
        for(int i=1; i<n; i++){
            int temp = max({nums[i], max_so_far*nums[i], min_so_far*nums[i]});
            min_so_far = min({nums[i], max_so_far*nums[i], min_so_far*nums[i]});
            max_so_far = temp;
            
            ans = max(ans, max_so_far);
        }
        return ans;
    }
};