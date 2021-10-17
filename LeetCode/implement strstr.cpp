class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = needle.length();
        if(m==0) return 0;
        
        int n = haystack.length();
        
        for(int i=0; i<=n-m; i++){
            if(haystack.substr(i, m) == needle) return i;
        }
        return -1;
    }
};