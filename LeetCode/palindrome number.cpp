class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x<0) return false;
        
        vector<int> arr;
        
        while(x!=0){
            arr.push_back(x%10);
            x = x/10;
        }
        
        int left = 0;
        int right = arr.size()-1;
        
        while(left<=right){
            if(arr[left]!=arr[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};