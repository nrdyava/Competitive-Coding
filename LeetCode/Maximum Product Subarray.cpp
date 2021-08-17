class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxp = INT_MIN;
        int temp = 1;
        for(int i=0; i<nums.size(); i++){
            if(temp == 0) temp = 1;
            temp*=nums[i];
            maxp = max(maxp, temp);
        }
        
        temp = 1;
        for(int i=nums.size()-1; i>=0; i--){
            if(temp == 0) temp = 1;
            temp*=nums[i];
            maxp = max(maxp, temp);
        }
        return maxp;
    }
};