class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            nums[nums[i]%(n+1) - 1] += (n+1);
        }
        
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]/(n+1) == 2) ans.push_back(i+1);
        }
        return ans;
    }
};