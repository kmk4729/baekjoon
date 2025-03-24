#include <iostream>

using namespace std;

int N,K;

int arr[10];

void dfs(int lev, int str_idx) {
	if (lev>K)
	{
		for (int i = 1; i <= K; i++)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = str_idx; i <= N; i++)
	{
		arr[lev] = i;
		dfs(lev + 1, i);
	}
}


int main() {
	cin >> N >> K;
	dfs(1, 1);

}