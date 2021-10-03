class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int, int> M;
        int n = nums.size();
        int sum = 0;
        int ans = 0;
        
        M[0] = -1;
        for(int i=0; i<n; i++){
            sum += (nums[i] == 1)?1:-1;
            if(M.count(sum) == 0) M[sum] = i;
            else ans = max(ans, i - M[sum]);
        }
        return ans;
    }
};