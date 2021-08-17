#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'formingMagicSquare' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY s as parameter.
 */

int formingMagicSquare(vector<vector<int>> s) {
    vector<int> ss;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            ss.push_back(s[i][j]);
        }
    }
    
    vector<int> temp{1, 2, 3, 4, 5, 6, 7, 8, 9};
    int minC = 1000;
    int tempC = 0;
    
    do{
        if(temp[0]+temp[1]+temp[2] == 15 && temp[3]+temp[4]+temp[5] == 15 && temp[6]+temp[7]+temp[8] == 15 && temp[0]+temp[3]+temp[6] == 15 && temp[1]+temp[4]+temp[7] == 15 && temp[0]+temp[4]+temp[8] == 15 && temp[2]+temp[4]+temp[6] == 15){
            
            for(int i=0; i<9; i++){
                tempC += abs(ss[i]-temp[i]);
            }
            
            minC = min(minC, tempC);
            tempC = 0;
        }
    }
    while(next_permutation(temp.begin(), temp.end()));
    
    return minC;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);

    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        string s_row_temp_temp;
        getline(cin, s_row_temp_temp);

        vector<string> s_row_temp = split(rtrim(s_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int s_row_item = stoi(s_row_temp[j]);

            s[i][j] = s_row_item;
        }
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
