class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        int left = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int right = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        right--;
        
        if (left!=nums.size() && nums[left] == target) ans[0] = left;
        if (right>=0 && nums[right] == target) ans[1] = right;
        return ans;
        
    }
};