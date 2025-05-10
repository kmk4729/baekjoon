#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;


int main() {
	int num,A, B;
	cin >> num >> A >> B;
	int counted = 1;
	while (true) {
		if (abs(A - B) <= 1) {
			if (A / 2 != B / 2) {
				break;
			}
		}
		if (A % 2 == 1) A = (A + 1) / 2;
		else if (A % 2 == 0) A = A / 2;
		int aa=1;
		if (B % 2 == 1) B = (B + 1) / 2;
		else if (B % 2 == 0) B = B/ 2;
		counted++;
		
	}
	cout << counted;
}