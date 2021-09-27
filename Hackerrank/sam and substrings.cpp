#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

/*
 * Complete the 'substrings' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING n as parameter.
 */

int substrings(string n) {
    int k = n.length();
    unsigned long long temp = n[0] - '0';
    unsigned long long ans = temp;
    
    for(int i=1; i<k; i++){
        temp = ((i+1)*(n[i] - '0') + 10*temp)%MOD;
        
        ans = (ans + temp)%MOD;  
    }
    return ans;   
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n;
    getline(cin, n);

    int result = substrings(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
