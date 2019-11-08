//
// Post :
// https://stackoverflow.com/questions/58760303/write-a-function-that-adds-parentheses-to-the-beginning-and-end-to-make-all-pare
//

#include <iostream>
#include <string>

using namespace std;

void PrintChar(unsigned int count, const char& c){
	while (count) {
		cout << c;
		count--;
	}
}

void pMatch(string& input) {
	string output;
	unsigned int pos_count = 0, neg_count = 0;
	for (unsigned int i = 0; i < input.size(); ++i) {

		if (input[i] == '('){
			if (neg_count != 0) {
				if (neg_count > pos_count) {
					PrintChar(neg_count - pos_count, '(');
					PrintChar(neg_count, ')');
				} else {
					PrintChar(pos_count, ')');
				}
				pos_count = 0;
				neg_count = 0;
			}
			cout << '(';
			pos_count++;
		} else {
			neg_count++;
		}

	}
	if (neg_count != 0) {
		if (neg_count > pos_count) {
			PrintChar(neg_count - pos_count, '(');
			PrintChar(neg_count, ')');
		} else {
			PrintChar(pos_count, ')');
		}

	} else {
		if (pos_count != 0)
			PrintChar(pos_count, ')');
	}

}

int main() {

	string s = ")(()(";

	cout << "INPUT: " << s << endl;

	cout << "OUTPUT: ";
	pMatch(s);

	return 0;
}

