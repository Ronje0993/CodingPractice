//
// Question link
// https://www.hackerrank.com/challenges/find-digits/problem
//

#include <bits/stdc++.h>

using namespace std;

// Complete the findDigits function below.
int findDigits(int n) {
    int n_digit = n;
    int count = 0;
    while (n_digit > 0){
        int digit = n_digit%10; //unit digit
        n_digit = n_digit/10;

        if (digit != 0 && n%digit == 0){
            count++;
        }
    }

    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = findDigits(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
