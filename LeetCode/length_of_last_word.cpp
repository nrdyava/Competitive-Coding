class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        stringstream ss(s);
        string temp;
        
        while(ss>>temp) ans = temp.length();
        return ans;
    }
};