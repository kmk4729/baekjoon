#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstring>
using namespace std;


int arr[20];
vector<string> vec;


int main() {
	string items;
	int N, M, lengcount;
	cin >> N >> M;
	lengcount = 0;
	for (int i = 0; i < N; i++)     //0 ~ 8  9개  N=9
	{
		cin >> items;
		vec.push_back(items);
		lengcount += items.size();
	}
	for (int i = 1; i < N; i++)
	{
		arr[i] = (M - lengcount) / (N - 1);
	}
	lengcount = lengcount + (arr[1] * (N - 1));
	if (lengcount < M) {
		for (int i = 1; i < N; i++)
		{
			if ('a' <= vec[i][0] && vec[i][0] <= 'z') {
				arr[i]++;
				lengcount++;
				if (lengcount >= M)break;
			}
		}
	}
	if (lengcount < M) {
		for (int i = N-1; i >=1; i--)
		{
			if ('A' <= vec[i][0] && vec[i][0] <= 'Z') {
				arr[i]++;
				lengcount++;
				if (lengcount >= M)break;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		cout << vec[i];
		for (int j = 0; j < arr[i+1]; j++)
		{
			cout << '_';
		}
	}
	return 0;
}