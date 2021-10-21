class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total_sum = 0;
        int curr_min = 0;
        int curr_max = 0;
        int min_sum = INT_MAX;
        int max_sum = INT_MIN;
        
        for(int i=0; i<nums.size(); i++){
            total_sum += nums[i];
            
            curr_max = max(nums[i], curr_max+nums[i]);
            max_sum = max(max_sum, curr_max);
            
            curr_min = min(nums[i], curr_min+nums[i]);
            min_sum = min(min_sum, curr_min);
        }
        
        return (max_sum > 0)?max(max_sum, total_sum - min_sum):*max_element(nums.begin(), nums.end());
        
    }
};