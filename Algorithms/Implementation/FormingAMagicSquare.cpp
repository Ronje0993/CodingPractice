#include <bits/stdc++.h>

using namespace std;
queue<int> MagicQ;

void SetQ(const vector<vector<int>>& square_){
    // Since the input square is always going to be 3 X 3
    // It can be put into while loop // I just didn't
    MagicQ.push(square_[0][0]);
    MagicQ.push(square_[0][1]);
    MagicQ.push(square_[0][2]);
    MagicQ.push(square_[1][2]);
    MagicQ.push(square_[2][2]);
    MagicQ.push(square_[2][1]);
    MagicQ.push(square_[2][0]);
    MagicQ.push(square_[1][0]);
}
void GetSq(vector<vector<int>>& square_){
    // Since the square is always going to be 3 X 3
    // It can be put into while loop // I just didn't
    square_[0][0] = MagicQ.front(); MagicQ.push(MagicQ.front()); MagicQ.pop();
    square_[0][1] = MagicQ.front(); MagicQ.push(MagicQ.front()); MagicQ.pop();
    square_[0][2] = MagicQ.front(); MagicQ.push(MagicQ.front()); MagicQ.pop();
    square_[1][2] = MagicQ.front(); MagicQ.push(MagicQ.front()); MagicQ.pop();
    square_[2][2] = MagicQ.front(); MagicQ.push(MagicQ.front()); MagicQ.pop();
    square_[2][1] = MagicQ.front(); MagicQ.push(MagicQ.front()); MagicQ.pop();
    square_[2][0] = MagicQ.front(); MagicQ.push(MagicQ.front()); MagicQ.pop();
    square_[1][0] = MagicQ.front(); MagicQ.push(MagicQ.front()); MagicQ.pop();
}

void Transpose(vector<vector<int>>& square_){
    // Since the square is always going to be 3 X 3
    // It can be put into while loop // I just didn't
    square_[0][0] = MagicQ.front(); MagicQ.pop();
    square_[1][0] = MagicQ.front(); MagicQ.pop();
    square_[2][0] = MagicQ.front(); MagicQ.pop();
    square_[2][1] = MagicQ.front(); MagicQ.pop();
    square_[2][2] = MagicQ.front(); MagicQ.pop();
    square_[1][2] = MagicQ.front(); MagicQ.pop();
    square_[0][2] = MagicQ.front(); MagicQ.pop();
    square_[0][1] = MagicQ.front(); MagicQ.pop();
    SetQ(square_);
}


void rotate(const int& times){
    int i = 0;
    while(i < times){
        int temp = MagicQ.front();
        MagicQ.pop();
        MagicQ.push(temp);
        i++;
    }
}
void turnLeft(vector<vector<int>>& square_){
    rotate(2);  //rotate twice
    GetSq(square_);
}

void Difference(int& min_cost){
    vector<int> orignal {8, 3, 4, 9, 2, 7, 6, 1};
    int temp, cost = 0, i = 0;

    while (i < 8){
        temp = MagicQ.front(); MagicQ.push(MagicQ.front()); MagicQ.pop();
        cost += abs(orignal[i] - temp);
        i++;
        if (cost >= min_cost){
            break ;
        }
    }

    while (i < 8){
        MagicQ.push(MagicQ.front()); MagicQ.pop();
        i++;
    }
    if (cost < min_cost){
        min_cost = cost;
    }
}    

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>>& InputSq) {
   int minimum_cost = INT16_MAX;

    SetQ(InputSq);
    for (int i = 1; i < 10; i++){
        if (i % 5 != 0){
            Difference(minimum_cost);
            turnLeft(InputSq);
        } else {
            Transpose(InputSq);
        }

    }
    return(minimum_cost + abs(5 - InputSq[1][1]));

}

int main()
{
    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    cout << result;


    return 0;
}
