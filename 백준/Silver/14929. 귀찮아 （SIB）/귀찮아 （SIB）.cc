#include <iostream>
#include <algorithm>

using namespace std;


int main() {

	int N;
	cin >> N;
	int minisum = 0;
	long sumd = 0;
	int num;
	cin >> num;
	minisum = num;
	for (int i = 1; i < N; i++)
	{
		cin >> num;
		sumd += minisum * num;
		minisum += num;

	}
	
	
	cout << sumd;
}