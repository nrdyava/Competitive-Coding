class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left, right, mid;
        left = 0;
        right = nums.size() - 1;
        
        while(left<=right){
            mid = (left+right)/2;
            if (nums[mid] == target) return mid;
            
            if (nums[left] <= nums[mid]){
                if (target < nums[mid] && target >= nums[left]) right = mid - 1;
                else left = mid + 1;
            }
            
            else{
                if (target > nums[mid] && target <= nums[right]) left = mid + 1;
                else right = mid - 1;
            }
        }
        return -1;
    }
};