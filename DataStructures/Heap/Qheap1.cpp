//
// Queestion Link
// https://www.hackerrank.com/challenges/qheap1/problem
//


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


int main() {
    set<int> Heap;

    int n = 0, instruction = 0;
    cin >> n;

    while (n > 0){
        cin >> instruction;
        if (instruction == 3){
            cout << *Heap.begin() << endl;            
        } else {
            if (instruction == 1) {
                int number = 0; cin >> number;
                Heap.insert(number);
            } else {
                int number = 0; cin >> number;
                Heap.erase(number);
            }
        }
        n--;
    }

    return 0;
}
