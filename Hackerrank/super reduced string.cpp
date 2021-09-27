#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    stack<char> stk;
    for(int i=0; i<s.length(); i++){
        if(stk.empty() || stk.top() != s[i]) stk.push(s[i]);
        else stk.pop();
    }
    if(stk.empty()) cout<< "Empty String";
    else{
        string ans = "";
        while(!stk.empty()){
            ans = stk.top()+ans;
            stk.pop();
        }
        cout<<ans;
    };
    
    return 0;n
}