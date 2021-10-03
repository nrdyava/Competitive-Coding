#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'sherlockAndAnagrams' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int sherlockAndAnagrams(string s) {
    unordered_map<string, int> M;
    int n = s.length();
    
    for(int i=0; i<n; i++){
        for(int j=1; j<n && i+j <= n; j++){
            vector<int> temp(26, 0);
        
            string subs = s.substr(i, j);
            for(char c: subs) temp[c - 'a']+=1;
            
            string key = "";
            for(int I:temp) key = key+to_string(I);
            
            M[key] += 1; 
        }
    }
    int ans = 0;
    for(auto m: M){
        ans = ans + (m.second * (m.second - 1))/2;
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
