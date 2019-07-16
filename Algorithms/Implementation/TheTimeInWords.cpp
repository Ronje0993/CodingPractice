//
// Find the Question at: https://www.hackerrank.com/challenges/the-time-in-words/problem
//

#include <bits/stdc++.h>

using namespace std;
string Teen[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "quarter", "sixteen", "seventeen", "eighteen", "nineteen" };
string Number[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine","ten", "eleven", "twelve"};
// Complete the timeInWords function below.
string timeInWords(int h, int m) {
    string Time;


    if(m == 0){
        Time  = Number[h] + " o' clock";
        return(Time);
    } else if(m == 15) {
        Time  = "quarter past " + Number[h];
        return(Time);
    } else if(m == 45) {
        Time  = "quarter to " + Number[h + 1];
        return(Time);
    } else if(m == 30) {
        Time  = "half past " + Number[h];
        return(Time);
    } else {
        string Minutes = " minutes ";
        string Past = "past ";
        if (m>30){
            m = 60 - m;
            Past = "to ";
            h += 1;
        }
        int SecondDigit = m/10;
        int UnitDigit = m%10;

        if (SecondDigit == 0){
            if (UnitDigit == 1){
                Minutes = " minute ";
            }
            Time = Number[UnitDigit] + Minutes + Past + Number[h];
        } else if (SecondDigit == 1){
            Time = Teen[UnitDigit] + Minutes + Past + Number[h];
        } else {
            Time = "twenty " + Number[UnitDigit] + Minutes + Past + Number[h];
        }
        return(Time);
        
    }

}

int main()
{
    int h;
    cin >> h;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = timeInWords(h, m);

    cout << result << "\n";


    return 0;
}
