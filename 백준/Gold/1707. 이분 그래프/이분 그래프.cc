#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int T, V, E, fi, se;

int arr[20002];
vector<int> vec[20002];
void init() {
	memset(arr, 0, sizeof(arr));
	for (int i = 0; i < 20002; ++i) {
		vec[i].clear();
	}

	cin >> V >> E;
	for (int i = 0; i < E; i++)
	{
		cin >> fi >> se;
		vec[fi].push_back(se);
		vec[se].push_back(fi);
	}
}

bool dfs(int num,int flag ) {
	for (int u : vec[num]) {
		if (arr[u] == -flag) return false;
		if (arr[u] == flag)continue;
		arr[u] = flag;
		bool result=dfs(u, -flag);
		if (result == false)return false;
	}
	return true;
}

void check() {
	for (int i = 1; i <= V; i++)
	{
		if (arr[i] == 0) {
			bool result2 = dfs(i, 1);
			if (result2 == false) {
				cout << "NO\n";
				return;
			}
		}
	}
	cout << "YES\n";
}

int main() {
	cin >> T;
	for (int test_case = 0; test_case < T; test_case++)
	{
		init();
		check();
		
	}
}