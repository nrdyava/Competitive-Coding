int Solution::longestValidParentheses(string A) {
    int n = A.length();
    stack<int> s;
    int lvp = 0;
    int last;

    for(int i=0; i<n; i++){
        if(A[i] == '(') s.push(i);
        else{
            if(!s.empty() && A[s.top()] == '('){
                s.pop();
                last = -1;
                if(!s.empty()) last = s.top();
                lvp = max(lvp, i-last);

            }
            else{
                s.push(i);
            }
        }
    }

    return lvp;
}
