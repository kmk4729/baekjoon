#include <queue>
#include <stack>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int dfs(vector<vector<int>>& vec1, int startx, int starty) {
	vector<int> vx = { -1, 0, 0, 1 };
	vector<int> vy = { 0, -1, 1, 0 };

	int count = 0;
	stack<int> stx;
	stack<int> sty;
	stx.push(startx);
	sty.push(starty);
	while (!stx.empty()) {
		int datax = stx.top();
		int datay = sty.top();
		if (vec1[datax][datay] == 1) {
			count++;
			vec1[datax][datay] = 0;
			stx.pop();
			sty.pop();
			for (int i = 0; i < 4; i++)
			{
				int nextx = datax + vx[i];
				int nexty = datay + vy[i];
				if (nextx < size(vec1) && nextx >= 0 && nexty < size(vec1) && nexty >= 0&&vec1[nextx][nexty]==1) {
					stx.push(nextx);
					sty.push(nexty);
				}
			}
		}
		else {
			stx.pop();
			sty.pop();
		}
	}
	return count;
}

int bfs(vector<vector<int>>& vec1, int start, vector<int>& found) {
	queue<int> st1;
	found[start - 1] = 1;
	cout << start << " ";
	for (int i = 0; i < size(vec1); i++)
	{
		if (vec1[i][start - 1] == 1 && found[i] == 0) {
			st1.push(i + 1);
		}
	}
	while (!st1.empty()) {
		int data = st1.front();
		if (found[data - 1] == 0) {
			cout << data << " ";
			found[data - 1] = 1;
			st1.pop();
			for (int i = 0;i<size(vec1);i++)
			{
				if (vec1[i][data - 1] == 1 && found[i] == 0) {
					st1.push(i + 1);
				}
			}
		}
		else {
			st1.pop();
		}
	}
	return 0;
}




int main() {
	int num;
	cin >> num;
	vector<vector<int>> vec1(num,vector<int> (num,0));
	priority_queue<int> pq;
	stack<int> st1;
	for (int k = 0; k < num; k++)
	{
		string str1;
		cin >> str1;
		for (int j = 0; j < num; j++)
		{
			if (str1[j] == '1') {
				vec1[k][j]++;
			}
		}
	}

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (vec1[i][j] == 1) {
				pq.push(dfs(vec1, i, j));
			}
		}
	}
	int pqsize = size(pq);
	for (int k = 0; k < pqsize; k++)
	{
		st1.push(pq.top());
		pq.pop();
	}
	
	cout <<pqsize<< endl;
	for (int i = 0; i < pqsize; i++)
	{
		cout << st1.top() << endl;
		st1.pop();
	}
	

}