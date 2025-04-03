#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cmath>	
using namespace std;

int N, K;
int result;
int map[9][9];
int visited[9][9];
int drow[4] = { -1,1,0,0 };
int dcol[4] = { 0,0,1,-1 };
int maxvalue;
struct point {
	int row, col;
};

void init() {
	memset(map, 0, sizeof(map));
	memset(visited, 0, sizeof(visited));
	maxvalue = 0;
	result = 0;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			maxvalue = max(map[i][j], maxvalue);
		}
	}
}

void dfs(int lastvalue, point pt, int lev, bool cheat) {
	for (int i = 0; i < 4; i++)
	{
		int nrow = pt.row + drow[i];
		int ncol = pt.col + dcol[i];
		if (nrow < 0 || ncol < 0 || nrow >= N || ncol >= N)continue;
		if (visited[nrow][ncol])continue;
		if (map[pt.row][pt.col] >= map[nrow][ncol])continue;
		visited[nrow][ncol] = 1;
		dfs(map[pt.row][pt.col], { nrow,ncol }, lev + 1, cheat);
		visited[nrow][ncol] = 0;
	}
	
	if (cheat == false) {
		for (int s = 1; s <= K; s++)
		{
			if ((map[pt.row][pt.col] - s) <= lastvalue) break;
			for (int i = 0; i < 4; i++)
			{
				int nrow = pt.row + drow[i];
				int ncol = pt.col + dcol[i];
				
				if (nrow < 0 || ncol < 0 || nrow >= N || ncol >= N)continue;
				if (visited[nrow][ncol])continue;
				if (map[pt.row][pt.col]-s >= map[nrow][ncol])continue;
				visited[nrow][ncol] = 1;
				dfs(map[pt.row][pt.col], { nrow,ncol }, lev + 1, true);
				visited[nrow][ncol] = 0;
			}
		}
	}
	if(maxvalue==map[pt.row][pt.col])result = max(result, lev);
}


int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				visited[i][j] = 1;
				if (test_case==5) {
					int aasg = 1;
				}
				dfs(-1,{ i,j }, 1,false);
				visited[i][j] = 0;
			}
		}
		cout << "#" << test_case << " " << result << '\n';
	}
	return 0;
}