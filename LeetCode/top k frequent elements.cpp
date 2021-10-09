class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> M;
        for(int i=0; i<nums.size(); i++) M[nums[i]]++;
        
        vector<pair<int, int>> vpairs;
        
        for(auto it:M){
            vpairs.push_back({it.second, it.first});
        }
        
        sort(vpairs.rbegin(), vpairs.rend());
        
        vector<int> ans;
        int temp=0;
        
        while(k--){
            ans.push_back(vpairs[temp].second);
            temp++;
        }
        return ans;
    }
};