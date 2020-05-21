//
// Question Link
// https://www.hackerrank.com/challenges/countingsort4/problem
//

#include <bits/stdc++.h>

using namespace std;


// Complete the countSort function below.
void countSort(vector<pair<int, string>>& arr, map<int, int>& counting_array) {
    map<int, int>::iterator it = counting_array.begin();
    map<int, int>::iterator prev = it;
    it++;
    for (; it != counting_array.end(); it++){
        it->second = it->second + prev->second;
        prev = it;
    }
    
    prev--;
    it--;
    for (; it != counting_array.begin(); it--){
        it->second = prev->second;
        prev--;
    }
    it->second = 0;

    int arr_size = arr.size();
    vector<string> res_str(arr_size);

    for (int i = 0; i < arr_size; i++) {
        res_str[counting_array[arr[i].first]++] = arr[i].second;
        // counting_array[arr[i].first]++;
    }

    for (int i = 0; i < arr_size; i++) {
        std::cout<< res_str[i] << " ";
    }
}

int main()
{
    int numOfElements; std::cin >> numOfElements;
    std::vector<std::pair<int, string>> arr(numOfElements);
    map<int, int> counting_array;
    
    for(int i = 0; i < numOfElements; i++){
        if (i >= (numOfElements/2)){
            std::cin >> arr[i].first >> arr[i].second;
        } else {
            std::string trash;
            std::cin >> arr[i].first >> trash;
            arr[i].second = "-";
        }
        if(counting_array.find(arr[i].first) == counting_array.end()){
            counting_array.insert({arr[i].first, 1});
        } else {
            counting_array[arr[i].first]++;
        }
    }

    // for(int i = 0; i < numOfElements; i++){
    //     std::cout << arr[i].first << " - " << arr[i].second << std::endl;
    // }
    countSort(arr, counting_array);

    return 0;
}
