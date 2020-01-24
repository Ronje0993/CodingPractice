//
// Question Link: 
// https://www.hackerrank.com/challenges/merging-communities/problem?isFullScreen=true
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N = 0, Query = 0;
    cin >> N >> Query;
    vector<int> parent(N,-1);

    int temp = Query;
    while (Query > 0)
    {
        char instruction;
        cin >> instruction;
        if (instruction == 'Q') {
            int I = 0;
            cin >> I;

            while (parent[I] >= 0) {
                I = parent[I];
            }
            cout << abs(parent[I]) << endl;
        } else if (instruction == 'M') {
            int I = 0, J = 0;
            cin >> I >> J;

            while (parent[I] >= 0) {
                I = parent[I];
            }
            while (parent[J] >= 0) {
                J = parent[J];
            }

            if (I != J){
                if (parent[J] < parent[I]) {
                    parent[J] += parent[I];
                    parent[I] = J;
                } else {
                    parent[I] += parent[J];
                    parent[J] = I;
                }
            }
        }

        Query--;
    }
    return 0;
}
