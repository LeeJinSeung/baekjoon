#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <cmath>
#include <stack>
#include <functional>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1000000;

int n, k, m, a, b, sq, c;
ll d;
ll tree[4 * MAX + 1];
ll lazy[4 * MAX + 1];

// 세그먼트 트리 구성
void init() {
	sq = 1;
	while (sq < n)
		sq *= 2;
}

void update(int idx, int val) {
	idx += sq - 1;
	tree[idx] = val;
	while (idx /= 2) {
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
	}
}

void update_lazy(int node, int start, int end) {
	if (lazy[node]) {
		tree[node] += (end - start + 1) * lazy[node];
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update_range(int left, int right, int node, int start, int end, ll diff) {
	update_lazy(node, start, end);

	if (right < start || end < left) return;

	if (left <= start && end <= right) {
		tree[node] += (end - start + 1) * diff;
		if (start != end) {
			lazy[node * 2] += diff;
			lazy[node * 2 + 1] += diff;
		}
		return;
	}

	int mid = (start + end) / 2;

	update_range(left, right, node * 2, start, mid, diff);
	update_range(left, right, node * 2 + 1, mid + 1, end, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int l, int r, int node, int start, int end) {
	update_lazy(node, start, end);

	if (r < start || end < l) return 0;
	if (l <= start && end <= r) return tree[node];

	int mid = (start + end) / 2;

	return query(l, r, node * 2, start, mid) + query(l, r, node * 2 + 1, mid + 1, end);
}


int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;

	init();
	for (int i = 0; i < n; i++) {
		cin >> tree[sq + i];
	}
	for (int i = sq - 1; i > 0; i--) {
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}


	for (int i = 0; i < m + k; i++) {
		cin >> a >> b >> c;

		if (b > c) swap(b, c);

		if (a == 1) {
			cin >> d;
			// update(b, c);ㅣ
			update_range(b, c, 1, 1, sq, d);
		}
		else if (a == 2) {
			cout << query(b, c, 1, 1, sq) << '\n';
		}
	}

	return 0;
}