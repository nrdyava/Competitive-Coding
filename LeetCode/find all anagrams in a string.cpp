class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
	
        vector<int> pHash (26, 0), sHash(26, 0);
        for(int i=0;i<p.length();i++) pHash[p[i] - 'a']++;
		
        int i = 0, j = 0;
        vector<int> ans;
        
        while(j < s.length())
        {   
            if(j - i >= p.length()) sHash[s[i] - 'a']--, i++;
            else sHash[s[j] - 'a']++, j++;
            
            if(j - i == p.length() && sHash == pHash) ans.push_back(i);
        }
        return ans;
    }
};