class Solution {
public:   
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const int &a, const int &b){return to_string(a)+to_string(b)>to_string(b)+to_string(a);});
        string ans = "";
        for(int i=0; i<nums.size(); i++){
            ans = ans+to_string(nums[i]);
        }
        if(ans[0] == '0') return "0";
        return ans;
    }
};