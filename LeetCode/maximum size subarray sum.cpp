class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int summ = 0;
        int ans = INT_MAX;
        
        for(int i=0; i<nums.size(); i++){
            summ+=nums[i];
            while(summ>=target){
                ans = min(ans, i-left+1);
                summ -= nums[left];
                left++;
            }
        }
        if(ans == INT_MAX) return 0;
        return ans;
    }
};