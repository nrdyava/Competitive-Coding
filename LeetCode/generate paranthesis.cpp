class Solution {
    void solver(string curr, int left, int right, vector<string> &ans, int n){
        if(left+right == 2*n){
            ans.push_back(curr);
            return;
        }
        
        if(left<n){
            curr.push_back('(');
            solver(curr, left+1, right, ans, n);
            curr.pop_back();
        }
        if(right<left){
            curr.push_back(')');
            solver(curr, left, right+1, ans, n);
            curr.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        int left = 0, right = 0;
        vector<string> ans;
        solver("", 0, 0, ans, n);
        return ans;
    }
};