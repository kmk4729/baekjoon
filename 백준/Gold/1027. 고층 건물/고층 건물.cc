#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;


double arr[51];
double temparr[51];
int main() {
	int N;
	cin >> N;
	int maxi = 0;
	int maxind = 0;
	double giulgi;
	int seecount, maxseecount;
	seecount = N - 1;
	maxseecount = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> temparr[i];
		if (arr[i] > maxi) {
			maxi = arr[i];
			//maxind = i;
		}
	}
	for (int maxind = 1;maxind <= N;maxind++) {
		seecount = N - 1;
		maxi = temparr[maxind];
		for (int i = 1; i <= N; i++)
		{
			arr[i] = temparr[i];
		}
		for (int i = maxind + 1; i <= N; i++)
		{
			if (arr[i] == 0)continue;
			giulgi = (maxi - arr[i]) / (i - maxind);
			for (int j = i + 1; j <= N; j++)
			{
				if (arr[j] != 0 && arr[j] <= maxi - (giulgi * (j - maxind))) {
					seecount--;
					arr[j] = 0;
				}
			}
		}
		for (int i = maxind - 1; i >= 1; i--)
		{
			if (arr[i] == 0)continue;
			giulgi = (maxi - arr[i]) / (maxind - i);
			for (int j = i - 1; j >= 1; j--)
			{
				if (arr[j] != 0 && arr[j] <= maxi - (giulgi * (maxind - j))) {
					seecount--;
					arr[j] = 0;
				}
			}
		}
		maxseecount = max(maxseecount, seecount);
	}

	cout << maxseecount;
}