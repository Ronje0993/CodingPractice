//
// Question Link:
// https://www.hackerrank.com/challenges/components-in-graph/problem?h_r=next-challenge&h_v=zen&isFullScreen=false
//
  
  
#include <bits/stdc++.h>
#include <climits>

using namespace std;

int main(){
    int n = 0;
    cin >> n;

    vector<int> parent(2*n, -1);

    for (int i = 0; i < n; i++){
        int a = 0, b = 0;
        cin >> a >> b;

        while(parent[a] >= 0) {
            a = parent[a];
        }

        while (parent[b] >= 0) {
            b = parent[b];
        }

        if (a != b) {
            if (parent[a] < parent[b]){
                parent[a] += parent[b];
                parent[b] = a;
            } else {
                parent[b] += parent[a];
                parent[a] = b;
            }
        }
    }
    int N = 2*n;
    int max = 0, min = INT_MIN;
    for (int i = 0; i < N; i++){
        if (parent[i] < 0 && parent[i] != -1) {
            if (max > parent[i]) {
                max = parent[i];
            }
            if (min < parent[i]) {
                min = parent[i];
            }
        }
    }

    cout << abs(min) << " " << abs(max) << endl;
    return 0;
}
