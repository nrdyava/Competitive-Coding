#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'marsExploration' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int marsExploration(string s) {
    int count = 0;
    int n = s.length();
    
    for(int i=0; i<n; i++){
        if((i%3 == 0 || i%3 == 2) && (s[i] != 'S')) count++;
        else if(i%3 == 1 && s[i] != 'O') count++;
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = marsExploration(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
