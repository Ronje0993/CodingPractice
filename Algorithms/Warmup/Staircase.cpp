//
// Question Link
// https://www.hackerrank.com/challenges/staircase/problem
//


#include <bits/stdc++.h>

using namespace std;

// Complete the staircase function below.
void staircase(int n) {
    for (int i = 0; i < n; i++) {
        string new_line = std::string(n-1-i, ' ') + std::string(i+1, '#');
        cout << new_line << endl;
    } 

}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    staircase(n);

    return 0;
}
