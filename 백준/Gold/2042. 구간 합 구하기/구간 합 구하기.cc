/*
5 2 2
1
2
3
4
5
1 3 6
2 2 5
1 5 2
2 3 5
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <algorithm>

using namespace std;


int N, M, K;
long long A, B, C;
long long arr[1000010];
long long segtree[4000040];




void init(int node, int left, int right) {
	if (left == right) {
		segtree[node] = arr[left];
		return;
	}

	int mid = (left + right) / 2;

	init(node * 2, left, mid);
	init(node * 2 + 1, mid+1, right);

	segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
	return;
}


void update(int node, int left, int right, int qindex, long long value) {
	if (qindex < left || right < qindex)return;
	if (left == right) {
		segtree[node] = arr[left];
		return;
	}
	int mid = (left + right) / 2;

	update(node * 2, left, mid, qindex, value);
	update(node * 2+1, mid+1, right, qindex, value);

	segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
	return;
}

long long sum(int node, int left, int right, int qleft, int qright) {
	if (qleft > right || left > qright)return 0;
	if (left == right) {
		return arr[left];
	}
	if (left >= qleft && qright >= right)return segtree[node];
	int mid = (left + right) / 2;



	return sum(node * 2, left, mid, qleft, qright) + sum(node * 2 + 1, mid + 1, right, qleft, qright);
}


int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	init(1, 0, N - 1);
	for (int i = 0; i < M+K; i++)
	{
		cin >> A >> B >> C;
		if (A == 1) {
			arr[B-1] = C;
			update(1, 0, N - 1, B - 1, C);
		}
		if (A == 2) {
			cout << sum(1, 0, N - 1, B-1, C-1) << '\n';
		}
	}

}
