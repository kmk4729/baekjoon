#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,K;
vector<int> v1;
int arr[10];
int visited[10];

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
	for (int i = 1; i <= N; i++)
	{
		if (visited[i])continue;
		visited[i] = 1;
		arr[lev] = v1[i];
		dfs(lev + 1, i);
		visited[i] = 0;
	}
}


int main() {
	cin >> N >> K;
	int data;
	v1.push_back(-2);
	for (int i = 0; i < N; i++)
	{
		cin >> data;
		v1.push_back(data);
	}
	sort(v1.begin(), v1.end());
	dfs(1, 1);

}