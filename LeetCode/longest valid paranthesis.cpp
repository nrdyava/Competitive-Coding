class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        stack<int> stk;
        
        stk.push(-1);
        int ans = 0;
        
        for(int i=0; i<n; i++){
            if(s[i]=='(') stk.push(i);
            else{
                stk.pop();
                if(!stk.empty()) ans = max(ans, i - stk.top());
                else stk.push(i);
            }
        }
        return ans;
    }
};