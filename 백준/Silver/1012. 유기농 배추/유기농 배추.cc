#include<iostream>
#include <vector>
#include <stack>
using namespace std;

int dfs(int row,int col, vector<vector<int>>& vec1) {
	stack<int> stx;
	stack<int> sty;
	stx.push(row);
	sty.push(col);
	vector<int> dx = { -1,0,0,1 };
	vector<int> dy = { 0,-1,1,0 };
	while (!stx.empty()) {
		int datax = stx.top();
		int datay = sty.top();
		stx.pop();
		sty.pop();
		if (vec1[datax][datay] == 1) {
			vec1[datax][datay] = 0;
			for (int i = 0; i < 4; i++)
			{
				if (vec1[datax + dx[i]][datay + dy[i]] == 1) {
					stx.push(datax + dx[i]);
					sty.push(datay + dy[i]);
				}
			}
		}
	}
	return 0;
}

int main() {
	int num;
	cin >> num;
	for (int k = 0; k < num; k++)
	{

		int col, row, ednum;
		int count = 0;
		cin >> row >> col >> ednum;
		vector<vector<int>> vec1(row + 2, vector<int>(col + 2, 0));

		for (int i = 0; i < ednum; i++)
		{
			int first, second;
			cin >> first >> second;
			vec1[first+1][second+1]++;
		}

		for (int i = 0; i <= row+1; i++)
		{
			for (int j = 0; j <= col+1; j++)
			{
				if (vec1[i][j] == 1) {
					count++;
					dfs(i,j, vec1);
				}
			}
		}
		cout << count<<endl;
	}
}