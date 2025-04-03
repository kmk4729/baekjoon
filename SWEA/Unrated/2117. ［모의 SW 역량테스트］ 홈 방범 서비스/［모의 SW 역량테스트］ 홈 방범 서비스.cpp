#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

// 집 기준으로 bfs 퍼져나가면서 각 위치에 거리 몇일 때 집이 있는지 넣어두기 3차원 배열임 x y dist 에 몇개의 집이 있는지 
int num,result,N,M;
struct point {
	int row, col,cost;
};

int arr[21][21][50];  // row col dist
int visited[21][21];
int drow[4] = { -1,1,0,0 };
int dcol[4] = { 0,0,-1,1 };

void bfs(point st) {
	memset(visited, 0, sizeof(visited));
	queue<point> q;
	q.push(st);
	visited[st.row][st.col] = 1;
	while (!q.empty()) {
		point now = q.front();
		q.pop();
		arr[now.row][now.col][now.cost]++;
		for (int i = 0; i < 4; i++)
		{
			int nrow = now.row + drow[i];
			int ncol = now.col + dcol[i];
			if (nrow < 0 || ncol < 0 || nrow >= N || ncol >= N)continue;
			if (visited[nrow][ncol])continue;
			visited[nrow][ncol] = 1;
			q.push({ nrow,ncol,now.cost+1 });

		}
	}
}

void init() {
	result = 0;	
	cin >> N >> M;
	memset(arr, 0, sizeof(arr));
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> num;
			if (num == 1) {
				bfs({ i,j,1 });
			}
		}
	}
}


void calculate() {
	int counthome = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			counthome = 0;
			for (int k = 1; k <= N*2; k++)
			{
				counthome += arr[i][j][k];
				int costt = (M * counthome) - (k * k) - ((k - 1) * (k - 1));
				if (costt >= 0) {
					result = max(result, counthome);
				}
			}
		}
	}
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
		calculate();
		cout << "#" << test_case << " " << result << '\n';
	}
	return 0;
}