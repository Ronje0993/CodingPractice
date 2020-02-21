//
// Question Link
// https://www.hackerrank.com/challenges/simple-text-editor/problem
//


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;


int main() {
    unsigned int Q = 0; std::cin >> Q;
    std::string S = "";
    std::stack<std::pair<bool, std::string>> UndoStack;   // bool as there are 
                                                     // only 2 options to do
                                                     // TRUE - append
                                                     // FALSE - delete
    while (Q > 0){
        unsigned int action = 0; std::cin >> action;
        switch (action){
            case 1:{
                std::string str; std::cin >> str;
                UndoStack.push(std::make_pair(false, str));
                S = S.append(str);
                break;
            }
            case 2: {
                unsigned int k = 0; std::cin >> k;
                unsigned int n = S.length();
                UndoStack.push(std::make_pair(true, S.substr(n - k, k)));
                S = S.substr(0, n-k);
                break;
            }
            case 3:{
                unsigned int k = 0; std::cin >> k;
                std::cout << S[k-1] << std::endl;
                break;
            }
            default:{
                if (UndoStack.top().first == true){
                    S.append(UndoStack.top().second);
                } else {
                    S = S.substr(0, S.length() - UndoStack.top().second.length());
                }
                UndoStack.pop();
                break;
            }
        }
        Q--;
    }
    return 0;
}
