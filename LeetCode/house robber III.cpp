class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        
        int temp;
        int a, b, c, d;
        
        a = nums[0];
        b = max(nums[0], nums[1]);
        
        for(int i=2; i<n-1; i++){
            temp = max(nums[i]+a, b);
            a = b;
            b = temp;
        }
        
        c = nums[1];
        d = max(nums[1], nums[2]);
        
        for(int i=3; i<n; i++){
            temp = max(nums[i]+c, d);
            c = d;
            d = temp;
        }
        
        return max(b, d);
    }
};