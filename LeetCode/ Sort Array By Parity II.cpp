class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++) if(nums[i]%2 == 0) nums[i] *= -1;
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size(); i++) if(nums[i] <= 0) nums[i] *= -1;
        int i=1;
        while(i < nums.size()/2){
            swap(nums[i], nums[nums.size() - i - 1]);
            i+=2;
        }
        return nums;
    }
};