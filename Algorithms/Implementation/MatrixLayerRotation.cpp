#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the matrixRotation function below.
void RotateMat(std::vector<std::vector<int>> &Mat, int &rot) {
  int row = Mat.size();
  int col = Mat[0].size();
  int circle_number = 0;
  std::queue<int> Que;

  int totalCircles = (std::min(row, col)) / 2;
  //    totalCircles = 1;
  while (circle_number < totalCircles) {
    for (int i = circle_number; i < col - circle_number; i++) {
      Que.push(Mat[circle_number][i]);
    }
    for (int i = circle_number + 1; i < row - (circle_number + 1); i++) {
      Que.push(Mat[i][col - (circle_number + 1)]);
    }
    for (int i = col - (circle_number + 1); i >= circle_number; i--) {
      Que.push(Mat[row - (circle_number + 1)][i]);
    }
    for (int i = row - (circle_number + 2); i > circle_number; i--) {
      Que.push(Mat[i][circle_number]);
    }

    int minimumRotation = rot % Que.size();
    for (int i = 0; i < minimumRotation; i++) {
      int temp = Que.front();
      Que.pop();
      Que.push(temp);
    }

    for (int i = circle_number; i < col - circle_number; i++) {
      Mat[circle_number][i] = Que.front();
      Que.pop();
    }
    for (int i = circle_number + 1; i < row - (circle_number + 1); i++) {
      Mat[i][col - (circle_number + 1)] = Que.front();
      Que.pop();
    }
    for (int i = col - (circle_number + 1); i >= circle_number; i--) {
      Mat[row - (circle_number + 1)][i] = Que.front();
      Que.pop();
    }
    for (int i = row - (circle_number + 2); i > circle_number; i--) {
      Mat[i][circle_number] = Que.front();
      Que.pop();
    }
    circle_number++;
  }

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cout << Mat[i][j] << " ";
    }
    cout << "\n";
  }
}

int main()
{
    string mnr_temp;
    getline(cin, mnr_temp);

    vector<string> mnr = split(rtrim(mnr_temp));

    int m = stoi(mnr[0]);

    int n = stoi(mnr[1]);

    int r = stoi(mnr[2]);

    vector<vector<int>> matrix(m);

    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    RotateMat(matrix, r);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
