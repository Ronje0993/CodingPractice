//
// Question Link    
// https://www.hackerrank.com/challenges/organizing-containers-of-balls/problem
//

#include <bits/stdc++.h>

using namespace std;

// Complete the organizingContainers function below.
string organizingContainers(vector<vector<int>> container) {
    int n = container.size();
    vector<int> total_balls_of_color(n, 0);
    vector<int> balls_in_container(n, 0);

    // Calculate total number of balls of each color/ number
    // Calculate total balls in each container
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            balls_in_container[i] += container[i][j];
            total_balls_of_color[j] += container[i][j];
        }
    }

    sort(balls_in_container.begin(), balls_in_container.end());
    sort(total_balls_of_color.begin(), total_balls_of_color.end());    
    // Now do this
    for (int i = 0; i < n; i++) {
        if(total_balls_of_color[i] != balls_in_container[i]){
            return("Impossible");
        }
    }

    return("Possible") ;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> container(n);
        for (int i = 0; i < n; i++) {
            container[i].resize(n);

            for (int j = 0; j < n; j++) {
                cin >> container[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string result = organizingContainers(container);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
