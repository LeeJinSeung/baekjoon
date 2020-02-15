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
#include <bitset>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 100000;

int n, k, m, a, b, sq, c;
int d;
int tree[4 * MAX + 1];
bool lazy[4 * MAX + 1];

// 技弊刚飘 飘府 备己
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
		tree[node] = (end - start + 1) - tree[node];
		if (start != end) {
			lazy[node * 2] = !lazy[node * 2];
			lazy[node * 2 + 1] = !lazy[node * 2 + 1];
		}
		lazy[node] = 0;
	}
}

void update_range(int left, int right, int node, int start, int end) {
	update_lazy(node, start, end);

	if (right < start || end < left) return;

	if (left <= start && end <= right) {
		tree[node] = (end - start + 1) - tree[node];
		if (start != end) {
			lazy[node * 2] = !lazy[node * 2];
			lazy[node * 2 + 1] = !lazy[node * 2 + 1];
		}
		return;
	}

	int mid = (start + end) / 2;

	update_range(left, right, node * 2, start, mid);
	update_range(left, right, node * 2 + 1, mid + 1, end);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int l, int r, int node, int start, int end) {
	update_lazy(node, start, end);

	if (r < start || end < l) return 0;
	if (l <= start && end <= r) return tree[node];

	int mid = (start + end) / 2;

	return query(l, r, node * 2, start, mid) + query(l, r, node * 2 + 1, mid + 1, end);
}


int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	init();
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;

		if (b > c) swap(b, c);

		if (a == 0) {
			update_range(b, c, 1, 1, sq);
		}
		else if (a == 1) {
			cout << query(b, c, 1, 1, sq) << '\n';
		}



	}

	return 0;
}