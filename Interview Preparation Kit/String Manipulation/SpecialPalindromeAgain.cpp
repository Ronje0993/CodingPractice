#include <bits/stdc++.h>

using namespace std;

// Complete the substrCount function below.
long substrCount(const string& s) {
    unsigned int count = 0;
    unsigned int n = s.length();
    for(unsigned int i = 1; i < n; i++){
    	int repeat = 1;
        int k = i-1;
        while(k>=0){
            if (s[i] == s[k]) {
                count += 1;
                repeat +=1;
                k -= 1;
            }else{
                k -= 1;
                break;
            }
        }

        while (repeat > 0 && k >= 0) {
            if (s[i] == s[k]) {
                repeat -= 1;
                k -= 1;
            }else{
                break;
            }
        }
        if (repeat == 0) {
        	count += 1;
        }
    }
    return (count + n);
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(s);

    cout << result;

    return 0;
}
