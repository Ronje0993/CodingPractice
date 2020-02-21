//
// Question Link
// https://www.hackerrank.com/challenges/jesse-and-cookies/problem
//


#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n = 0, k = 0;
    cin >> n >> k;

    priority_queue<int> MH; 

    int val = 0;
    for (int i = 0; i < n; i++){
        cin >> val;
        val = -1 * val;
        MH.push(val);
    }

    int count = -1;
    
    while (abs(MH.top()) < k && MH.size() > 1){
        count++;
        int a = MH.top(); MH.pop();
        int b = MH.top(); MH.pop();

        int c = -1 * (abs(a) + (2 * abs(b)));

        MH.push(c);
    }
    count++;
  
    if ((abs(MH.top()) < k && MH.size() < 2))
        cout << "-1" << endl;
    else
        cout << count << endl;

    return 0;
}
