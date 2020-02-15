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

const int MOD = 1000000007;

int n, k, m, a, b, sq;
ll c;
ll arr[4000001];

// 技弊刚飘 飘府 备己
void init() {
	sq = 1;
	while (sq < n)
		sq *= 2;
}

void update(int idx, int val) {
	idx += sq - 1;
	arr[idx] = val;
	while (idx /= 2) {
		arr[idx] = (arr[idx * 2] * arr[idx * 2 + 1]) % MOD;
	}
}

ll cal(int l, int r, int nodeNum, int nodeL, int nodeR) {
	if (r < nodeL || nodeR < l) return 1;
	if (l <= nodeL && nodeR <= r) return arr[nodeNum];
	int mid = (nodeL + nodeR) / 2;
	return (cal(l, r, nodeNum * 2, nodeL, mid) * cal(l, r, nodeNum * 2 + 1, mid + 1, nodeR)) % MOD;
}


int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;

	init();
	for (int i = 0; i < n; i++) {
		cin >> arr[sq + i];
	}
	for (int i = sq - 1; i > 0; i--) {
		arr[i] = (arr[i * 2] * arr[i * 2 + 1]) % MOD;
	}


	for (int i = 0; i < m + k; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(b, c);
		}
		else if (a == 2) {
			cout << cal(b, c, 1, 1, sq) << '\n';
		}
	}

	return 0;
}