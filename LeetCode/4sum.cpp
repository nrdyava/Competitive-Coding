class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size()<4) return{};
        vector<vector<int>> ans;
        int n = nums.size();
        int left, right, temp_sum;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n-3; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j=i+1; j<n-2;j++){
                if(j>i+1 && nums[j] == nums[j-1]) continue;
                
                left = j+1;
                right = n-1;
                
                while(left < right){
                    temp_sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (temp_sum == target){
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while(left<right && nums[left] == nums[left+1]) left++;
                        while(left<right && nums[right] == nums[right-1]) right--;
                        left++;
                        right--;
                    }
                    else if(temp_sum < target) left++;
                    else right--;
                }
            }
        }
        return ans;
    }
};