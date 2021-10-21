class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sln = s.length();
        queue<char> q;
        for(int i=0; i<sln; i++){
            q.push(s[i]);
        }
        
        for(int i=0; i<t.length(); i++){
            if(t[i] == q.front()){
                q.pop();
            }
            if(q.size() == 0) return true;
        }
        if(q.size() == 0) return true;
        return false;
    }
};