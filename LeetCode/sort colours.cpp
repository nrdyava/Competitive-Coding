class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, r = nums.size()-1, p=0;
        
        while(p<=r){
            if(nums[p] == 0){
                swap(nums[p], nums[l]);
                l++;
                p++;
            }
            else if(nums[p] == 2){
                swap(nums[p], nums[r]);
                r--;
                p++;
            }
            else{
                p++;
            }
        }
    }
};