class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxreach = 0;
        
        for(int i=0; i<n; i++){
            maxreach = max(maxreach, i+nums[i]);
            if(maxreach == i && i<n-1) return false;
        }
        return true;
    }
};