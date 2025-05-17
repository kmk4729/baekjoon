#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>



using namespace std;

int N, M;
char ch;
struct node {
	int row, col, cost;
};

int map[1001][1001];
int drow[4] = { -1,1,0,0 };
int dcol[4] = { 0,0,1,-1 };
queue<node> fq;
queue<node> jq;

void firebfs() {
	while (!fq.empty()) {
		node now = fq.front();
		fq.pop();
		for (int i = 0; i < 4; i++)
		{
			int nr = now.row + drow[i];
			int nc = now.col + dcol[i];
			if (nr < 0 || nc < 0 || nr >= N || nc >= M)continue;
			if (map[nr][nc] != 0)continue;
			map[nr][nc] = now.cost + 1;
			fq.push({ nr,nc,now.cost + 1 });
		}
	}
}

int bfs() {
	while (!jq.empty()) {
		node now = jq.front();
		jq.pop();
		for (int i = 0; i < 4; i++)
		{
			int nr = now.row + drow[i];
			int nc = now.col + dcol[i];
			if (nr < 0 || nc < 0 || nr >= N || nc >= M)return now.cost;
			if (map[nr][nc]!=0&&map[nr][nc] <=now.cost+1)continue;
			map[nr][nc] = -2;
			jq.push({ nr,nc,now.cost + 1 });
		}
	}
	return -1;
}

int main() {
	cin >> N >> M;
	memset(map, -1, sizeof(map));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			map[i][j] = 0;
			cin >> ch;
			if (ch == '#')  map[i][j] = -2;
			if (ch == 'J') {
				jq.push({ i,j,1 });

			}
			if (ch == 'F') {
				map[i][j] = 1;
				fq.push({ i,j,1 });
			}
			
		}
	}
	firebfs();
	int result = bfs();
	if (result == -1) cout << "IMPOSSIBLE";
	else cout << result;

}