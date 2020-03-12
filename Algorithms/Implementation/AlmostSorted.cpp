//
// Question Link:
// https://www.hackerrank.com/challenges/almost-sorted/problem
//


#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

string swapCondition(const vector<int>& arr, const int& minVal, const int& maxVal,  unsigned int& i){
    string swp_str = "";
    unsigned int arr_len = arr.size();
    unsigned int start = i-2;

    if (arr[i] > maxVal) {
        while (arr[i] > arr[i-1] && i < arr_len){
            i++;
        }
        if (i != arr_len){
            swp_str = "no";
            return swp_str;
        } else {
            swp_str = "yes\nswap " + to_string(start + 1) + " " + to_string(start + 2);
            return swp_str;
        }
    }

    while (arr[i] > arr[i-1] && i < arr_len ) {
        if (arr[i] >= maxVal){
            swp_str = "no";
            return swp_str;
        }
        i++;
    }

    if (i == arr_len){
        swp_str = "no";
        return swp_str;
    } else if (i == arr_len) {
        if (arr[i] > minVal && arr[i] < arr[start + 1]){
            swp_str = "yes\nswap " + to_string(start + 1) + " " + to_string(arr_len);
        } else {
            swp_str = "no";
            return swp_str;
        }
    } else {
        unsigned int stop = i;
        i++;
        if (arr[i] <= maxVal){
            swp_str = "no";
            return swp_str;
        }
        while (i < arr_len){
            if (arr[i] <= arr[i-1]){
                swp_str = "no";
                return swp_str;
            }
            i++;
        }

        if (i == arr_len){
            swp_str = "yes\nswap " + to_string(start + 1) + " " + to_string(stop + 1);
        } else {
            swp_str = "no";
        }
    }


    return swp_str;
}

string reverseCondition(const vector<int>& arr, const int& minVal, const int& maxVal,  unsigned int i){
    string rev_str = "";
    unsigned int start = i-2;
    unsigned int arr_len = arr.size();
    while (i < arr_len) {
        if (arr[i] < minVal) {
            rev_str = "no";
            return rev_str;
        }
        if (arr[i] >= arr[i-1]) {
            break;
        }
        i++;
    }
    if (i == arr_len){
        rev_str = "yes\nreverse " + to_string(start + 1) + " " + to_string(arr_len);
    } else if (arr[i] <= maxVal) {
        rev_str = "no";
    } else {
        unsigned int stop = i-1;
        while (arr[i] > arr[i-1] && i < arr_len) {
            i++;
        }
        if (i == arr_len){
            rev_str = "yes\nreverse " + to_string(start + 1) + " " + to_string(stop + 1);
        } else {
            rev_str = "no";
        }
    }
    return rev_str;
}

void almostSorted(const vector<int>& arr) {
    int minVal = INT_MIN, maxVal = 0;
    unsigned int i = 1, maxVal_index = UINT_MAX;
    unsigned int arr_len = arr.size();
    string result_str = "";

    while (i < arr_len) {
        if (i != 1) {
            minVal = arr[i-2];
        }
        if (i == arr_len - 1){
            result_str = "yes";
        }
        
        if (arr[i] <= arr[i-1]) {
            if (arr[i] <= minVal || arr[i] == arr[i-1]) {
                result_str = "no";
                break;
            }

            maxVal = arr[i-1];
            // maxVal_index = i-1;
            
            if (i == arr_len - 1){
                result_str = "yes\nswap " + to_string(arr_len - 1) + " " + to_string(arr_len);
                break;
            }

            if (arr[i] > arr[i+1]) {
                result_str = reverseCondition(arr, minVal, maxVal, ++i);
                break;
            } else if (arr[i] < arr[i+1]) {
                result_str = swapCondition(arr, minVal, maxVal, ++i);
                break;
            }
        } else {
            i++;
        }
    }

    cout << result_str << endl;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    almostSorted(arr);

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
