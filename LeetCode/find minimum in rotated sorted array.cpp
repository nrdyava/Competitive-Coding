class Solution {
public:
    int findMin(vector<int>& nums) {
        int l, r, mid;
        l = 0;
        r = nums.size()-1;
        
        if(nums.size() == 1) return nums[0];
        
        if(nums[l]<nums[r]) return nums[l];
        
        while(l <= r){
            mid = l+(r - l)/2;
            
            if(nums[mid] > nums[mid+1]) return nums[mid+1];
            else if(nums[mid]<nums[mid-1]) return nums[mid];
            else if(nums[mid]>nums[0]){
                l = mid+1;
            }
            else r = mid - 1;
        }
        return mid;
    }
};