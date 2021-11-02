class Solution {
public:
    void solver(int i, int n, vector<vector<int>> &ans, vector<int> nums){
        if(i == n){
            ans.push_back(nums);
        }
        
        for(int j = i; j<n; j++){
            swap(nums[i], nums[j]);
            solver(i+1, n, ans, nums);
            swap(nums[i], nums[j]);
        }
        return;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> curr;
        solver(0, n, ans, nums);
        return ans;
    }
};