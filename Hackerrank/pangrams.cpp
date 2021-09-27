#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'pangrams' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string pangrams(string s) {
    int arr[26] = {0};
    for(int i=0; i<s.length(); i++){
        if(s[i] - 'a' >= 0 && s[i] - 'a' <26) arr[s[i] - 'a'] = 1;
        else if(s[i] - 'A' >= 0 && s[i] - 'A' <26) arr[s[i] - 'A'] = 1;
        else continue;
    }
    int prod = 1;
    for(int i=0; i<26; i++){
        prod = prod * arr[i];
    }
    if(prod == 1) return "pangram";
    else return "not pangram";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
