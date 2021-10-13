class Solution {    
public:
    string longestPalindrome(string s) {
        int max = 0;
        int l = 0;
        int r = 0;
        string res = "";
        
        for(int i = 0 ; i < s.length(); i++)
        {
            //Odd pal
            l = i;
            r = i;
            while(l >= 0 && r < s.length() && s[l] == s[r])
            {
                if(r-l+1 > max)
                {
                    res =  s.substr(l, r-l+1);
                    max = r - l + 1;
                }
                
                l--;
                r++;
            }
            
            l = i;
            r =i+1;
            while(l >= 0 && r < s.length() && s[l] == s[r])
            {
                if(r-l+1 > max)
                {
                    res = s.substr(l , r-l+1);
                    max = r-l+1;
                }
                l--;
                r++;
            }
            
            
        }
        
        return res;
    }
};