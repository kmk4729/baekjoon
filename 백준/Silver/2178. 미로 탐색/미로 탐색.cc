#include<iostream>
#include <vector>
#include <queue>
using namespace std;

int bfs(int row,int col, vector<vector<int>>& vec1) {
	queue<int> qx;
	queue<int> qy;
	qx.push(row);
	qy.push(col);
	vector<int> dx = { -1,0,0,1 };
	vector<int> dy = { 0,-1,1,0 };
	while (!qx.empty()) {
		int datax = qx.front();
		int datay = qy.front();
		qx.pop();
		qy.pop();
		for (int i = 0; i < 4; i++)
		{
			if (vec1[datax + dx[i]][datay + dy[i]] == 1) {
				vec1[datax + dx[i]][datay + dy[i]] = vec1[datax][datay] + 1;
				qx.push(datax + dx[i]);
				qy.push(datay + dy[i]);
			}
		}
		
	}
	return 0;
}

int main() {
	int row, col;
	cin >> row >> col;
	vector<vector<int>> vec1(row+2, vector<int>(col+2, 0));
	string str;
	for (int i = 0; i < row; i++)
	{
		cin >> str;
		for (int j = 0; j < col; j++)
		{
			if (str[j] == '1')
				vec1[i+1][j+1]++;
		}
	}
	bfs(1, 1, vec1);
	cout << vec1[row][col] << endl;

}