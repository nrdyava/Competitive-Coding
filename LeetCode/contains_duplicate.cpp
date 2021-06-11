class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> um;
        for (int i = 0; i<nums.size(); i++){
            um[nums[i]] +=1;
        }
        for (auto ume:um){
            if (ume.second >1) return true;
        }
        return false;
    }
};