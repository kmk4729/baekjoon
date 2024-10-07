#include<iostream>
#include <vector>
#include <stack>
using namespace std;

int dfs(int start, vector<vector<int>>& vec1) {
	stack<int> st1;
	st1.push(start);
	while (!st1.empty()) {
		int data = st1.top();
		st1.pop();
		for (int i = 0; i < size(vec1); i++)
		{
			if (vec1[data][i] == 1) {
				st1.push(i);
				vec1[data][i] = 0;
				vec1[i][data] = 0;
			}
		}
	}
	return 0;
}

int main() {
	int nnum, ednum;
	int count = 0;
	cin >> nnum >> ednum;
	vector<vector<int>> vec1(nnum+1, vector<int>(nnum+1, 0));
	vector<int> vec2(nnum+1, 0);

	for (int i = 0; i < ednum; i++)
	{
		int first, second;
		cin >> first >> second;
		vec1[first][second]++;
		vec1[second][first]++;
		vec2[first]++;
		vec2[second]++;
	}
	for (int i = 1; i < size(vec2); i++)
	{
		if (vec2[i] == 0) {
			count++;
		}
	}
	for (int i = 0; i <= nnum; i++)
	{
		for (int j = 0; j <= nnum; j++)
		{
			if (vec1[i][j] == 1) {
				count++;
				dfs(i, vec1);
			}
		}
	}
	cout << count;
}