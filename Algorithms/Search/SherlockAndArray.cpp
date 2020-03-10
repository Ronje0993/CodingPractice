//
// Question Link
// https://www.hackerrank.com/challenges/sherlock-and-array/problem?utm_campaign=challenge-recommendation&utm_medium=email&utm_source=24-hour-campaign
//

#include <iostream>
#include <vector>

using namespace std;

int main(){

    unsigned int testcases = 0; cin >> testcases;
    while (testcases > 0){
        unsigned int numOfElements = 0; cin >> numOfElements;
        vector<unsigned int> arr(numOfElements);
        unsigned int sum = 0;

        for (unsigned int i = 0; i < numOfElements; i++){
            cin >> arr[i];
            sum += arr[i];
        }

        unsigned int left_sum = 0;
        unsigned int i = 0;
        for (; i < numOfElements; i++){
            sum -= arr[i];
            if (i > 0){
                left_sum += arr[i-1]; 
            }

            if (left_sum == sum){ 
                cout << "YES" << endl;
                break;
            }
            
        }

        if (i == numOfElements){
            cout << "NO" << endl;
        }

        testcases--;
        
    }
}
