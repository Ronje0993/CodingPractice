/************************************************
 * This solution uses the multiplication and
 * division operators which can be replaced 
 * by their bit manipulation operators.
 ***********************************************/
#include <bits/stdc++.h>

using namespace std;

long getclosesttwopower(long n) {
    long number = 1;
    while(number < n){
        //number = number << 1;
        number = number * 2;
    }
    //number = number >> 1;
    number = number / 2;
    return number;
}
// Complete the counterGame function below.
bool counterGame(long n) {
  bool player = true;
  while (n > 1) {
    long mynumber = getclosesttwopower(n);

    if (mynumber == n) {
      n = n / 2;
    } else {
      n = n - mynumber;
    }

    if (n == 1) {
      break;
    } else {
      player = !player;
    }
  }
  return (player);
}

int main()
{
  int t;
  cin >> t;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int t_itr = 0; t_itr < t; t_itr++) {
    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    bool result = counterGame(n);

    (result == true) ? cout << "Louise" << endl : cout << "Richard" << endl;
        
    }

    return 0;
}
