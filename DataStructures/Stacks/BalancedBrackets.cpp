//
// Question link
// https://www.hackerrank.com/challenges/balanced-brackets/problem
//


#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) {
    stack<char> bin;
    char ch = s[0];
    unsigned int i = 0;
    while (ch != '\0'){
        if (ch == '{' || ch == '[' || ch == '('){
            bin.push(ch);
        } else {
            if (bin.empty()){
                return("NO");
            }
            char check = bin.top();
            if (ch == '}'){
                if (check != '{'){
                    return("NO");
                } else {
                    bin.pop();
                }
            } else if (ch == ']'){
                if (check == '['){
                    bin.pop();
                } else {
                    return("NO");
                    
                }
            } else {
                if (check != '('){
                    return("NO");
                } else {
                    bin.pop();
                }
            }
        }
        ch = s[++i];
    }

    if (bin.empty()){
        return("YES");
    } else {
        return("NO");
    }


}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        cout << result << "\n";
    }

    return 0;
}
