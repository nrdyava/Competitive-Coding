class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size();
        if(n<3) return 0;
        int ans = 0;
        sort(nums.begin(), nums.end());
        
        int start, end;
        int total;
        
        for(int i=0; i<n-2; i++){
            
            start = i+1;
            end = n-1;
            while(start<end){
                total = nums[i]+nums[start]+nums[end];
                if(total>=target) end--;
                else{
                    ans+=end-start;
                    start++;
                }
            }
        }
        return ans;
    }
};