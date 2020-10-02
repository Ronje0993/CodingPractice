//
// QUESTION LINK
// https://www.hackerrank.com/challenges/3d-surface-area/problem
//

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int H, W;
    scanf("%d%d", &H, &W);

    vector<vector<int>> A(H);
    int prev = 0;
    int surface_area = 0;
    for (int i = 0; i < H; i++) {
        A[i].resize(W);
        for (int j = 0; j < W; j++) {
            scanf("%d", &A[i][j]);
            surface_area += abs(A[i][j] - prev);
            prev = A[i][j]; 
        }
        surface_area += prev;
        prev = 0; 
    }

    for (int j = 0; j < W; j++) {
        for (int i = 0; i < H; i++) {
            surface_area += abs(A[i][j] - prev);
            prev = A[i][j]; 
        }
        surface_area += prev;
        prev = 0; 
    }

    surface_area += (2*H*W);
    cout << surface_area << endl;
}
