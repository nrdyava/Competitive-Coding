class Solution {
public:
    void sortColors(vector<int>& nums) {
        int ncolors[3] = {0, 0, 0};
        for (int i=0; i<nums.size(); i++) ncolors[nums[i]]+=1;
        for (int i=0; i<ncolors[0]; i++){
            nums[i] = 0;
        }
        for (int i=ncolors[0]; i<ncolors[0]+ncolors[1]; i++){
            nums[i] = 1;
        }
        for (int i=ncolors[0]+ncolors[1]; i<ncolors[0]+ncolors[1]+ncolors[2]; i++){
            nums[i] = 2;
        }
    }
};