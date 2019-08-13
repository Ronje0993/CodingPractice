#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
std::queue<pair<int, int>> Bombspots;
std::queue<pair<int, int>> Next_Bombspots;

void FillPlaces(vector<string>& grid){
    while(!Next_Bombspots.empty()){
        grid[Next_Bombspots.front().first][Next_Bombspots.front().second] = 'O';
        Next_Bombspots.pop();
    }
}

void FindBomb(vector<string>& grid){
    for (unsigned int i = 0; i < grid.size(); i++){
        for (unsigned int j = 0; j < grid[i].length(); j++){
            if (grid[i][j] == 'O'){
                Bombspots.push(make_pair(i,j));
            }
        }
    }
}

void BombNow(vector<string>& grid){
    while(!Bombspots.empty()){
        unsigned int r = Bombspots.front().first;
        unsigned int c = Bombspots.front().second;
        grid[r][c] = '.';
        Next_Bombspots.push(make_pair(r,c));

        if(r != grid.size() - 1){
           grid[r+1][c] = '.';
           Next_Bombspots.push(make_pair(r+1,c));
        }

        if(r != 0){
           grid[r-1][c] = '.';
           Next_Bombspots.push(make_pair(r-1,c));
        }

        if(c != grid[r].length() - 1){
           grid[r][c+1] = '.';
           Next_Bombspots.push(make_pair(r,c+1));
        }

        if(c != 0){
           grid[r][c-1] = '.';
           Next_Bombspots.push(make_pair(r,c-1));
        }

        Bombspots.pop();
    }
}

// Complete the bomberMan function below.
vector<string> bomberMan(int n, vector<string>& grid) {
    for(unsigned int i = 0; i < grid.size(); i++){
        for (unsigned int j = 0; j< grid[i].length(); j++){
            if (grid[i][j] == 'O'){
                Bombspots.push(make_pair(i,j));
            }else{
                Next_Bombspots.push(make_pair(i,j));
            }
        }
    }

    for (int i = 1; i < n; i++){
        if (i%2==0){
            BombNow(grid);
            FindBomb(grid);
        } else {
            FillPlaces(grid);
        }

    }

    return(grid);
}

int main()
{
    string rcn_temp;
    getline(cin, rcn_temp);

    vector<string> rcn = split_string(rcn_temp);

    int r = stoi(rcn[0]);

    int c = stoi(rcn[1]);

    int n = stoi(rcn[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }
    if (n > 4){
        n = 6- (n % 4);   // Calculate the minimum times the loop should run
        if(n % 2 == 0 ){
            n = 2;
        }
    }
    vector<string> result = bomberMan(n, grid);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

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

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
