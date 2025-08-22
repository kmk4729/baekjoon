#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define ll long long

using namespace std;

int N, M, K;
ll arr[1000010];
ll segtree[4000040];
ll Lazyprop[4000040];
int A, B,C;
ll D;

void init(int node, int left, int right) {
	if (left == right) {
		segtree[node] = arr[left];
		return;
	}
	int mid = (left + right) / 2;

	init(node * 2, left, mid);
	init(node * 2 + 1, mid + 1, right);

	segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
	return;
}


void lazyupdate(int node, int left, int right) {
	if (Lazyprop[node] != 0) {
		segtree[node] = segtree[node] + (right - left + 1) * Lazyprop[node];

		if (left != right) {
			Lazyprop[node * 2] = Lazyprop[node * 2] + Lazyprop[node];
			Lazyprop[node * 2+1] = Lazyprop[node * 2+1] + Lazyprop[node];
		}
		Lazyprop[node] = 0;
	}
	return;
}

void update(int node, int left, int right , int qleft, int qright, ll value) {
	lazyupdate(node, left, right);
	if (qright < left || right < qleft) return;
	if (qleft <= left && right <= qright) {
		segtree[node] = segtree[node] + (right - left + 1) * value;
		if (left != right) {
			Lazyprop[node * 2] = Lazyprop[node * 2] + value;
			Lazyprop[node * 2 + 1] = Lazyprop[node * 2 + 1] + value;
		}
		return;
	}

	int mid = (left + right) / 2;
	update(node * 2, left, mid, qleft, qright, value);
	update(node * 2 + 1, mid + 1, right, qleft, qright, value);

	segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
	return;

}

ll query(int node ,int left, int right , int qleft ,int qright) {
	lazyupdate(node, left, right);
	if (qright < left || right < qleft)return 0;
	if (qleft <= left && right <= qright) return segtree[node];
	int mid = (left + right) / 2;
	ll leftsum = query(node * 2, left, mid, qleft, qright);
	ll rightsum = query(node*2+1,mid+1,right,qleft,qright);
	return leftsum + rightsum;
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
		cin >> A;
		if (A == 1) {
			cin >> B >> C >> D;
			update(1, 0, N - 1, B-1, C-1, D);
		}
		if (A == 2) {
			cin >> B >> C;
			cout << query(1, 0, N - 1, B-1, C-1) << '\n';
		}
	}

}
