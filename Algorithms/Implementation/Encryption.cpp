#include <bits/stdc++.h>

using namespace std;
string removeSpaces(string& s){
  unsigned int count = 0;
  for (unsigned int i = 0;i < s.length(); i++)
    if (s[i] != ' ') {
      s[count++] = s[i];
    }
  s[count] = '\0';
  return(s);
}
// Complete the encryption function below.
string encryption(string& s) {
    string tempString = removeSpaces(s);
    double length = sqrt(tempString.length());
    unsigned int rows = floor(length); // getting rows
    unsigned int cols = ceil(length);  // getting cols

    vector<string> encrypt(cols);

    for (unsigned int i = 0; i < tempString.length(); i++){
      encrypt[i % cols] = encrypt[i % cols] + tempString[i];
    }

    tempString = encrypt[0];
    for (unsigned int i = 1; i < cols; i++){
        tempString = tempString + " "+ encrypt[i];
    }

    return (tempString);
}

int main()
{
    string s;
    getline(cin, s);

    string result = encryption(s);

    cout << result << "\n";
    return 0;
}
