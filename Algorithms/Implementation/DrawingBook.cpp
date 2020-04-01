//
// Question link:
// https://www.hackerrank.com/challenges/drawing-book/problem
//

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the pageCount function below.
 */
int pageCount(int n, int p) {
    return min (floor(p/2), floor(n/2) - floor(p/2));

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = pageCount(n, p);

    fout << result << "\n";

    fout.close();

    return 0;
}
