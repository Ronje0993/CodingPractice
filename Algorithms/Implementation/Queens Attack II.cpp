#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <unordered_set>


using namespace std;


vector<string> split_string(string input_string) {
  string::iterator new_end =
      unique(input_string.begin(), input_string.end(),
             [](const char &x, const char &y) { return x == y and x == ' '; });


  input_string.erase(new_end, input_string.end());


  while (input_string[input_string.length() - 1] == ' ') {
    input_string.pop_back();
  }


  vector<string> splits;
  char delimiter = ' ';


  size_t i = 0;
  size_t pos = input_string.find(delimiter);


  while (pos != string::npos) {
    splits.push_back(input_string.substr(i, pos - i));


    i = pos + 1;
    pos = input_string.find(delimiter, i);
  }


  splits.push_back(
      input_string.substr(i, min(pos, input_string.length()) - i + 1));


  return splits;
}


int non_diagonal_count(const int &r_q, const int &c_q, const int &N,
                       const vector<unordered_set<int>> &O) {
  int count = 0;


  // UP
  for (int i = r_q + 1; i < N; i++) {
    if (O[i].find(c_q) != O[i].end()) {
      break;
    } else {
      count++;
    }
  }


  // DOWN
  for (int i = r_q - 1; i >= 0; i--) {
    if (O[i].find(c_q) != O[i].end()) {
      break;
    } else {
      count++;
    }
  }


  // LEFT
  for (int i = c_q - 1; i >= 0; i--) {
    if (O[r_q].find(i) != O[i].end()) {
      break;
    } else {
      count++;
    }
  }


  // RIGHT
  for (int i = c_q + 1; i < N; i++) {
    if (O[r_q].find(i) != O[i].end()) {
      break;
    } else {
      count++;
    }
  }


  return (count);
}


int diagonal_count(const int &r_q, const int &c_q, const int &N,
                   const vector<unordered_set<int>> &O) {
  int count = 0;


  // LEFT - UP
  int new_cq = c_q - 1;
  for (int i = r_q + 1; i < N; i++) {
    if (new_cq >= 0) {
      if (O[i].find(new_cq) != O[i].end()) {
        break;
      } else {
        count++;
      }
    } else {
      break;
    }
    new_cq -= 1;
  }


  // LEFT - DOWN
  new_cq = c_q - 1;
  for (int i = r_q - 1; i >= 0; i--) {
    if (new_cq >= 0) {
      if (O[i].find(new_cq) != O[i].end()) {
        break;
      } else {
        count++;
      }
    } else {
      break;
    }
    new_cq -= 1;
  }


  // RIGHT - DOWN
  new_cq = c_q + 1;
  for (int i = r_q - 1; i >= 0; i--) {
    if (new_cq < N) {
      if (O[i].find(new_cq) != O[i].end()) {
        break;
      } else {
        count++;
      }
    } else {
      break;
    }
    new_cq += 1;
  }


  // RIGHT - UP
  new_cq = c_q + 1;
  for (int i = r_q + 1; i < N; i++) {
    if (new_cq < N) {
      if (O[i].find(new_cq) != O[i].end()) {
        break;
      } else {
        count++;
      }
    } else {
      break;
    }
    new_cq += 1;
  }


  return (count);
}


int main() {


  string nk_temp;
  getline(cin, nk_temp);


  vector<string> nk = split_string(nk_temp);


  int n = stoi(nk[0]);


  int k = stoi(nk[1]);


  string r_qC_q_temp;
  getline(cin, r_qC_q_temp);


  vector<string> r_qC_q = split_string(r_qC_q_temp);


  int r_q = stoi(r_qC_q[0]) - 1;


  int c_q = stoi(r_qC_q[1]) - 1;


  vector<unordered_set<int>> obs(n);
  for (int i = 0; i < k; i++) {
    string obstacle;
    getline(cin, obstacle);


    vector<string> obstacle_S = split_string(obstacle);
    obs[stoi(obstacle_S[0]) - 1].insert(stoi(obstacle_S[1]) - 1);
  }


  int count =
      non_diagonal_count(r_q, c_q, n, obs) + diagonal_count(r_q, c_q, n, obs);
  cout << count;


  return 0;
}
