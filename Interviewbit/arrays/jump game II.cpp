class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int lookup[n];
        for (int i = 0; i < n; i++) {
            lookup[i] = INT_MAX;
        }
        
        lookup[0] = 0;
        
        for(int i=0; i<n; i++){
            for(int j=1; j<=min(nums[i], n-1) && (i+j < n); j++){
                lookup[i+j] = (lookup[i+j] != INT_MAX)?min(lookup[i+j], lookup[i]+1):(lookup[i]+1);
            }
        }
        return lookup[n-1];
    }
};