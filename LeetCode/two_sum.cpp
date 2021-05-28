class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map <int, int> umap;
        
        for (int i=0; i<nums.size(); i++){
            if (umap.find(nums[i]) == umap.end()){
                umap[target - nums[i]] = i;
            }
            else{
                ans.push_back(umap[nums[i]]);
                ans.push_back(i);
                return ans;
            }
        }
        return ans;
    }
};