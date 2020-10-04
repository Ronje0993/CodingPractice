//
// Question Link
// https://www.hackerrank.com/challenges/common-child/problem
//

#include <bits/stdc++.h>

using namespace std;

// Complete the commonChild function below.
int commonChild(string s1, string s2) {
    int n = s1.size();
    vector<vector<int>> DP_table(n+1);
    for (int i = 0; i <= n; i++) {
        DP_table[i].resize(n+1);
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                DP_table[i][j] = 0;
                continue;
            }

            if (s1[i-1] == s2[j-1]) {
                DP_table[i][j] = 1 + DP_table[i-1][j-1];
            } else {
                DP_table[i][j] = max(DP_table[i][j-1], DP_table[i-1][j]);
            }
        }
    }
    return DP_table[n][n];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
