#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

struct Edge {
	int num, cost;
};

struct cmp {
	bool operator()(Edge a, Edge b) {
		return a.cost > b.cost;
	}
};

vector<Edge> vec[1001];
int dist[1001];
int N, M, fir, sec, tri;
int st, en;

void dijkstra(int stnum) {
	priority_queue<Edge, vector<Edge>, cmp> pq;
	pq.push({ stnum,0 });
	dist[stnum] = 0;
	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();
		if (dist[now.num] < now.cost)continue;
		for (Edge u : vec[now.num]) {
			Edge next = { u.num,u.cost + now.cost };
			if (next.cost < dist[next.num]) {
				dist[next.num] = next.cost;
				pq.push(next);
			}
		}
	}
}


int main(){
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		dist[i] = 1e8;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> fir >> sec >> tri;
		vec[fir].push_back({ sec,tri });
	}
	cin >> st >> en;
	dijkstra(st);

	cout << dist[en];
}
