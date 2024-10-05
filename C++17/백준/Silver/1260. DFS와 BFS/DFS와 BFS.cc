#include <queue>
#include <stack>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int dfs(vector<vector<int>>& vec1, int start, vector<int>& found) {
	stack<int> st1;
	found[start - 1] = 1;
	cout << start << " ";
	for (int i = size(vec1) - 1; i >= 0; i--)
	{
		if (vec1[i][start - 1] == 1 && found[i] == 0) {
			st1.push(i+1);
		}
	}

	while (!st1.empty()) {
		int data = st1.top();
		if (found[data - 1] == 0) {
			cout << data << " ";
			found[data - 1] = 1;
			st1.pop();
			for (int i = size(vec1)-1; i >=0; i--)
			{
				if (vec1[i][data - 1] == 1 && found[i] == 0) {
					st1.push(i+1);
				}
			}
		}
		else {
			st1.pop();
		}
	}
	return 0;
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
	int nodenum, edgenum, startnode;
	cin >> nodenum >> edgenum >> startnode;
	vector<vector<int>> vec1(nodenum,vector<int> (nodenum,0));
	vector<int> found(nodenum, 0);
	vector<int> found2(nodenum, 0);

	for (int k = 0; k < edgenum; k++)
	{
		int first, second;
		cin >> first >> second;
		vec1[second - 1][first - 1] = 1;
		vec1[first - 1][second - 1] = 1;
	}
	
	dfs(vec1, startnode, found);
	cout << endl;
	bfs(vec1, startnode, found2);

}