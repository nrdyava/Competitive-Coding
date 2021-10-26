class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.length();
        int dp[n];
        
        dp[0] = 1;
        for(int i=0; i<n; i++){
            if(i==0 || s[i]!=s[i-1]){
                dp[i] = 1;
            }
            else if(s[i] == s[i-1]){
                dp[i] = dp[i-1]+1;
                if(dp[i] == k){
                    s.erase(i-k+1, k);
                    i = i-k;
                }
            }
        }
        return s;
    }
};