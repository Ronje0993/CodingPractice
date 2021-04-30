//
//
// https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem?h_l=interview&h_r=next-challenge&h_v=zen&isFullScreen=false&playlist_slugs%5B%5D%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D%5B%5D=dictionaries-hashmaps
//


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'sherlockAndAnagrams' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int sherlockAndAnagrams(string s) {
    int s_len = s.length();
    unordered_map<string, int> subStrs;
    for(int ss_len = 1; ss_len < s_len ; ss_len++) {
        for (int pos = 0; pos+ss_len <= s_len; pos++) {
            string sub_str = s.substr(pos, ss_len);
            sort(sub_str.begin(), sub_str.end());
            
            subStrs[sub_str]++;
        }
    }
    
    int total_pairs = 0;
    for(auto it:subStrs){
        if (it.second > 1){
            total_pairs += ((it.second * (it.second - 1))/2);
        }
    }
    
    return total_pairs;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

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
