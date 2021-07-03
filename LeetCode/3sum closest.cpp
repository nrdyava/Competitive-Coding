class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int temp_sum, mcs;
        int n = nums.size();
        int left, right;
        int ans;
        
        for(int i=0;i<n;i++){
            
            left = i+1;
            right = n-1;

            while(left < right){
                temp_sum = nums[i] + nums[left] + nums[right];
                if (abs(temp_sum - target) < abs(mcs - target)){
                    mcs = temp_sum;
                }
                
                else if(temp_sum < target) left++;
                else right --;
            }
        }
        return mcs;
    }
};