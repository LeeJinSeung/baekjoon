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

int n, q, sq, a, b, c;
ll st[4000001];

void init() {
	sq = 1;
	while (sq < n)
		sq *= 2;
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

	cin >> n >> q;

	init();

	for (int i = 0; i < q; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			int idx = sq + b - 1;
			st[idx] += c;
			while (idx /= 2) {
				st[idx] = st[idx * 2] + st[idx * 2 + 1];
			}
		}
		else if (a == 2) {
			cout << cal(b, c, 1, 1, sq) << '\n';
		}
	}

	return 0;
}