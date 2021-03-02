//
// Question link
// https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/yassers-conditions-6cc26a09/
//

#include <iostream>
#include <vector>

using namespace std;
class Solution{
private:
	vector<int> m_A;
	vector<int> m_Sums;
	int m_ArraySize;

	int sumOfDigits(int n){
		int sum = 0;
		while (n > 0){
			sum += (n % 10);
			n = n / 10;
		}
		return sum;
	}

public:

	Solution(int N){
		m_ArraySize = N;
		m_A.resize(N);
		m_Sums.resize(N);
	}

	int getSum(const int& index) {return m_Sums[index];}
	int getValue(const int& index) {return m_A[index];}

	void populateArray(){
		int i = 0;
		while (i < m_ArraySize){
			cin >> m_A[i];
			m_Sums[i] = sumOfDigits(m_A[i]);
			i++;
		}
	}


};

int main() {
	
	int N, Q;
	cin >> N >> Q;
	
	Solution S(N);

	S.populateArray();
	int i;

	while(Q > 0){
		cin >> i;
		i--;
		int Sum_A_i = S.getSum(i);
		int number = S.getValue(i++);
		int re_ind = -1;

		while (i < N){
			if (S.getValue(i) > number){
				int Sum_A_j =  S.getSum(i);
				if (Sum_A_i > Sum_A_j){
					re_ind = ++i;
					break;
				}
			} 
			i++;
		}
		cout << re_ind << endl;
		Q--;
	} 	



}
