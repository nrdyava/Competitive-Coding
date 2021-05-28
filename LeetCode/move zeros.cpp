class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nzeros = count(nums.begin(), nums.end(), 0);
        auto newit = remove(nums.begin(), nums.end(), 0);
        for (auto i = newit; i!=nums.end(); i++){
            *i = 0;
        }
    }
};