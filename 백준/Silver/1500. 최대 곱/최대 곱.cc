#include <iostream>
#include <cmath>
using namespace std;




int main() {
	int S, K;
	cin >> S >> K;
	unsigned long long result = 1;
	int mok = S / K;
	int namugi = S % K;
	result = pow(mok, K - namugi);
	result *= pow(mok + 1, namugi);
	cout << result;
}