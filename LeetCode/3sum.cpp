class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        if (nums.size()  < 3) return {};
        
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int left, right;
        int temp_sum;
        
        for(int i=0;i<n;i++){
            
            if ( i>0 && nums[i-1] == nums[i]) continue;
                
            left = i+1;
            right = n-1;

            while(left < right){
                temp_sum = nums[i] + nums[left] + nums[right];
                if (temp_sum == 0){
                    ans.push_back({nums[i], nums[left], nums[right]});
                    while(left < right && nums[left] == nums[left+1]) left++;
                    while(left < right && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;
                }
                
                else if(temp_sum < 0) left++;
                else right --;
            }
        }
        return ans;
    }
};