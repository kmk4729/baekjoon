#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;


int N, M;          // N-1 , M-1 좌표가 목표 지점이다.
char ch;
int map[101][101];
int dist[101][101];
int drow[4] = { -1,1,0,0 };
int dcol[4] = { 0,0,1,-1 };

struct Edge {
	int row, col;
	int cost;
};

struct cmp {
	bool operator()(Edge a, Edge b) {
		return a.cost > b.cost;

	}
};

int dijkstra() {
	dist[0][0] = 0;
	int nextcost = 0;
	priority_queue<Edge, vector<Edge>, cmp> pq;
	pq.push({ 0,0,0 });
	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();
		if (now.cost > dist[now.row][now.col])continue;
		if (now.row == N - 1 && now.col == M - 1)return now.cost;

		for (int i = 0; i < 4; i++)
		{
			int nr = now.row + drow[i];
			int nc = now.col + dcol[i];
			if (nr < 0 || nc < 0 || nr >= N || nc >= M)continue;
			if (map[nr][nc] == 0) nextcost = now.cost;
			if (map[nr][nc] == 1)nextcost = now.cost + 1;
			if (nextcost < dist[nr][nc]) {
				dist[nr][nc] = nextcost;
				pq.push({ nr,nc,nextcost });
			}

		}
	}
}

int main() {
	cin >> M >> N;
	memset(map, -1, sizeof(map));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			dist[i][j] = 1e8;
			cin >> ch;
			if (ch == '0')map[i][j] = 0;
			if (ch == '1')map[i][j] = 1;
		}
	}
	cout << dijkstra();
	return 0;
}