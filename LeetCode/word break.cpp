class Solution {
    bool solver(string s, vector<string> &wordDict, vector<int> &lookup){
        int n = s.length();
        if(n == 0) return true;
        
        if(lookup[n]==-1){
            lookup[n] = 0;
            for(int i=1; i<=n; i++){
                if(find(wordDict.begin(), wordDict.end(), s.substr(0, i))!=wordDict.end() && solver(s.substr(i), wordDict, lookup)) return lookup[n] = 1;
            }
        }
        
        return lookup[n]; 
    }
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<int> lookup(n+1, -1);
        return solver(s, wordDict, lookup);
        
    }
};