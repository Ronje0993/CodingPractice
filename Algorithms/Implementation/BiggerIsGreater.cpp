#include <bits/stdc++.h>

using namespace std;

// Complete the biggerIsGreater function below.
string biggerIsGreater(string& w) {
    unsigned int index_low = 0, index_hi = 0;

    for (unsigned int i = 0; i < w.length()-1; i++){  // O(N)
        if(w[i] < w[i+1]){
            index_low = i;
            index_hi = i+1;
        } else {
            if (w[i+1] > w[index_low]){
                index_hi = i+1;
            }
        }
    }

    if(index_low < index_hi){
        char temp = w[index_hi];
        w[index_hi] = w[index_low];
        w[index_low] = temp;

        sort(w.begin()+index_low+1, w.end());      // O(N.logN)
        return (w);
    } else {
        return ("no answer");
    }
}

int main()
{
    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        // string result = biggerIsGreater(w);

        cout << biggerIsGreater(w) << "\n";
    }
    return 0;
}
