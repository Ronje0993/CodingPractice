//
//Question link:
// https://www.hackerrank.com/challenges/queue-using-two-stacks/copy-from/137404196
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;


class MyDummyQueue{
private:
    std::stack<int> s1, s2;

public:

    void enqueue(const int& entry){
        s1.push(entry);
    }

    void dequeue(void){
        if (s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
    }

    void printTop(void){
        if (s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        std::cout << s2.top() <<std::endl;
    }
};

int main() {
    unsigned int q = 0; //Number of queries
    std::cin >> q;
    std::cin.ignore(1, '\n');

    MyDummyQueue que;
    string s;
    for (unsigned int i = 0; i < q; i++){
        std::getline(std::cin, s);
        
        size_t pos = s.find(' ');
        if (pos == string::npos){
            int task = stoi(s);
            if (task == 2){
                que.dequeue();
            } else{
                que.printTop();
            }
        } else {
            int number = stoi(s.substr(pos+1));
            que.enqueue(number);
        }
    }

    return 0;
}
