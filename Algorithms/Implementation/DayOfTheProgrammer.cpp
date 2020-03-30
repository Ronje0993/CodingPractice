//
// Question link
// https://www.hackerrank.com/challenges/day-of-the-programmer/problem?utm_campaign=challenge-recommendation&utm_medium=email&utm_source=24-hour-campaign&isFullScreen=true
//

#include <bits/stdc++.h>
#include <string>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// Complete the dayOfProgrammer function below.
string dayOfProgrammer(int year) {
    int remaining = 13;
    if (year <= 1917) {
        if (year%4 == 0){
            remaining = 12;
        }
    } else if (year > 1918) {
        if (year%400 == 0 || ((year%4 == 0) && (year%100 != 0))){
            remaining = 12;
        }
    } else {
        remaining += 13;
    }
    
    return to_string(remaining)+".09."+to_string(year);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string year_temp;
    getline(cin, year_temp);

    int year = stoi(ltrim(rtrim(year_temp)));

    string result = dayOfProgrammer(year);

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
