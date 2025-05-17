#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>


using namespace std;

struct Edge {
	int num;
	int cost;
};
struct cmp {
	bool operator()(Edge a, Edge b) {
		return a.cost > b.cost;
	}
};
vector<Edge> nor[1001];
vector<Edge> rev[1001];
int dist1[1001];
int dist2[1001];

int N, M, X;
int fir, sec, thi;

void dijkstra1(int st) {
	priority_queue<Edge, vector<Edge>, cmp> pq;
	pq.push({ st,0 });
	dist1[st] = 0;
	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();
		if (now.cost > dist1[now.num])continue;
		for (Edge u : nor[now.num]) {
			if (now.cost + u.cost < dist1[u.num]) {
				dist1[u.num] = now.cost + u.cost;
				pq.push({ u.num,now.cost + u.cost });
			}
		}
	}
}
void dijkstra2(int st) {
	priority_queue<Edge, vector<Edge>, cmp> pq;
	pq.push({ st,0 });
	dist2[st] = 0;
	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();
		if (now.cost > dist2[now.num])continue;
		for (Edge u : rev[now.num]) {
			if (now.cost + u.cost < dist2[u.num]) {
				dist2[u.num] = now.cost + u.cost;
				pq.push({ u.num,now.cost + u.cost });
			}
		}
	}
}

int main() {
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++)
	{
		cin >> fir >> sec >> thi;
		nor[fir].push_back({ sec,thi });
		rev[sec].push_back({ fir,thi });
	}

	for (int i = 1; i <= N; i++)
	{
		dist1[i] = 1e8;
		dist2[i] = 1e8;
	}

	dijkstra1(X);
	dijkstra2(X);
	int result = 0;
	for (int i = 1; i <= N; i++)
	{
		result = max(result, dist1[i] + dist2[i]);
	}

	cout << result;

}