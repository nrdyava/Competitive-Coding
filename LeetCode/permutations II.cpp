class Solution {
public:
    
    void solver(int i, int n, set<vector<int>> &uns, vector<int> nums){
        if(i == n){
            uns.insert(nums);
        }
        
        for(int j = i; j<n; j++){
            swap(nums[i], nums[j]);
            solver(i+1, n, uns, nums);
            swap(nums[i], nums[j]);
        }
        return;
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        set<vector<int>> uns;
        
        int n = nums.size();
        vector<int> curr;
        solver(0, n, uns, nums);
        
        vector<vector<int>> ans(uns.begin(), uns.end());
        
        return ans;
    }
};