class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int arr[128] = {0};
        
        int n = s.length();
        int left = 0;
        int right = 0;
        
        int res = 0;
        
        while(right<n){
            char c = s[right];
            arr[c]++;
            
            while(arr[c]>1){
                char l = s[left];
                arr[l]--;
                left++;
            }
            
            res = max(res, right-left+1);
            right++;
        }
        return res;
    }
};