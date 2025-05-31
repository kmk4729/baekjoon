#include <iostream>
#include <queue>

using namespace std;


long long A, B;


struct node {
	long long num;
	int cost;
};

long long bfs() {
	long long next;
	queue<node> q;
	q.push({ A,1 });
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		next = now.num * 10 + 1;
		if (next == B)return now.cost+1;
		if (next < B) {
			q.push({ next,now.cost + 1 });
		}
		next = now.num * 2;
		if (next == B)return now.cost+1;
		if (next < B) {
			q.push({ next,now.cost + 1 });
		}
	}
	return -1;
}

int main() {
	cin >> A >> B;
	cout << bfs();
}