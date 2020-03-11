//
// Question Link:
// https://www.hackerrank.com/challenges/time-conversion/problem
//

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(const string& s) {
    int hour = stoi(s.substr(0,2));
    string ret_str = s.substr(2,6);
    
    if (s[s.length()-2] == 'A'){
        if (hour == 12){
            ret_str = "00" + ret_str;
        } else {
            ret_str = s.substr(0,2) + ret_str;
        }
    } else {
        if (hour == 12){ hour = 0; }
        hour += 12;

        ret_str = to_string(hour) + ret_str;
    }

    return ret_str;


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
