class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        int pivot;
        
        while(l<r){
            pivot = l+(r-l)/2;
            if(nums[pivot]<nums[r]) r = pivot;
            else if(nums[pivot] > nums[r]) l = pivot+1;
            else r--;
        }
        return nums[l];
    }
};