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

const int INF = 1000000001;
const int MAX = 100000;

int n, m, sq, a, b;
int tree[4 * MAX + 1];

void init() {
	sq = 1;
	while (sq < n) sq *= 2;
}

int query(int l, int r, int node, int nodeL, int nodeR) {
	if (r < nodeL || l > nodeR) return INF;
	if (l <= nodeL && nodeR <= r) return tree[node];
	int mid = (nodeL + nodeR) / 2;
	return min(query(l, r, 2 * node, nodeL, mid), query(l, r, 2 * node + 1, mid + 1, nodeR));
}


int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	init();
	for (int i = 0; i < n; i++) cin >> tree[sq + i];

	for (int i = sq - 1; i > 0; i--) tree[i] = min(tree[i * 2], tree[i * 2 + 1]);

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		if (a > b) swap(a, b);
		cout << query(a, b, 1, 1, sq) << '\n';
	}


	return 0;
}