class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int p = 1<<n;
        set<vector<int>> S;
        
        for(int i=0; i<p; i++){
            vector<int> temp;
            for(int j=0; j<n; j++){
                if(i & (1<<j)) temp.push_back(nums[j]);
            }
            S.insert(temp);
        }
        vector<vector<int>> ans(S.begin(), S.end());
        return ans;
    }
};