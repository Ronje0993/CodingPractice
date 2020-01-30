//
// Question link:
// https://www.hackerrank.com/challenges/maximum-element/problem
//


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class Stack{
private:
    stack<unsigned int> max;
    stack<unsigned int> S;
public:
    Stack(){
        max.push(0);
    }
    void Add(unsigned int& val){
        S.push(val);
        if (max.top() <= val){
            max.push(val);
        }
    }

    void Delete(){
        if (S.top() == max.top()){
            max.pop();
        }
        S.pop();
    }

    void PrintMax(){
        cout << max.top() << endl;
    }
};

int main() {
    unsigned int n = 0;
    cin >> n;
    unsigned int q = 0;
    Stack myStack;
    for (unsigned int i = 0; i < n; i++){
        cin >> q;
        switch(q){
        case 1:{
            unsigned int val = 0;
            cin >> val;
            myStack.Add(val);
            break;
        }
        case 2: {
            myStack.Delete();
            break;
        }
        case 3: {
            myStack.PrintMax();
            break;
        }
        default:
            break;


        }
    }
    return 0;
}
