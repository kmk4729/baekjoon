#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>	

using namespace std;


bool cmp(int a, int b) {
	return abs(a) < abs(b);
}

vector<int> vec;

int N;
int A;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A;
		vec.push_back(A);
	}
	sort(vec.begin(), vec.end(), cmp);

	int sumd = 2000000001;
	int left =0 , right=0;
	for (int i = 0; i < N-1; i++)
	{
		if (abs(vec[i] + vec[i + 1]) < sumd) {
			left = vec[i];
			right = vec[i + 1];
			sumd = abs(vec[i] + vec[i + 1]);
		}
	}

	if(left>right) cout << right << " " << left;
	else cout << left << " " << right;
}