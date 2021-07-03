class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> LISvec(n, 1);
        
        for (int i=1; i<n; i++){
            for (int j=0; j<i; j++){
                if(nums[i] > nums[j]) LISvec[i] = max(LISvec[i],LISvec[j] + 1);
            }
        }
        
        return *max_element(LISvec.begin(), LISvec.end());
    }
};