class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxx = 0;
        int temp = 0;
        int n = nums.size();
        
        for(int i=0; i<n; i++) {
            if (nums[i] == 1) {
                temp+=1;
                maxx = max(maxx, temp);
            }
            else temp = 0;
        }
        return maxx;
    }
};