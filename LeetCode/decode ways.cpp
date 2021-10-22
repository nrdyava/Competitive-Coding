class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n, 0);
        
        int dig;
        int pdig;
        
        if(s[0] == '0') return 0;
        dp[0] = 1;
        
        for(int i=1; i<n; i++){
            dig = s[i] - '0';
            if(dig >0){
                dp[i] = dp[i-1];
            }
            
            pdig = s[i-1] - '0';
            if(pdig > 0){
                int num = 10*pdig+dig;
                if(num>0 && num <=26){
                    if(i-2>=0) dp[i] += dp[i-2];
                    else dp[i]++;
                }
            } 
        }
        return dp[n-1];
        
    }
};