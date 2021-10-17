class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        
        int left_sum[n], right_sum[n];
        left_sum[0] = 0;
        right_sum[n-1] = 0;
        
        for(int i=1; i<n; i++) left_sum[i] = left_sum[i-1]+nums[i-1];
        for(int i=n-2; i>=0; i--) right_sum[i] = right_sum[i+1]+nums[i+1];
        
        int maxx = INT_MIN;
        int max_index;
        
        for(int i=0; i<n; i++){
            if(left_sum[i] == right_sum[i]){
                return i;
            }   
        }
        
        return -1;
    }
};