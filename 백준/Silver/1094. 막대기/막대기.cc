#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int N;
	cin >> N;
	int stickcount = 0;
	while (N > 0) {
		int stick = 64;
		while (stick > N) {
			stick /= 2;
		}
		N -= stick;
		stickcount++;
	}
	cout << stickcount;
}