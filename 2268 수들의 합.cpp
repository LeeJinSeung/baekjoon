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

const int MAX = 1000000001;

int n, m, sq, a, b, c;
ll st[4000001];

void init() {
	sq = 1;
	while (sq < n)
		sq *= 2;
}

void update(int i, ll val) {
	int idx = (i - 1) + sq;
	st[idx] = val;
	while (idx /= 2)
		st[idx] = st[idx * 2] + st[idx * 2 + 1];
}

ll cal(int l, int r, int nodeNum, int nodeL, int nodeR) {
	if (r < nodeL || nodeR < l) return 0;
	if (l <= nodeL && nodeR <= r) return st[nodeNum];
	int mid = (nodeL + nodeR) / 2;
	return cal(l, r, nodeNum * 2, nodeL, mid) + cal(l, r, nodeNum * 2 + 1, mid + 1, nodeR);
}



int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	init();

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (a == 0) {
			if (b > c) swap(b, c);
			cout << cal(b, c, 1, 1, sq) << '\n';
		}
		else if (a == 1) {
			update(b, c);
		}
	}

	return 0;
}