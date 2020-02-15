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

int n, k, m, a, b, sq;
ll c;
ll arr[4*MAX + 1];

// ���׸�Ʈ Ʈ�� ����
void init() {
	sq = 1;
	while (sq < n)
		sq *= 2;
}

void update(int idx, int val) {
	idx += sq - 1;
	arr[idx] = val;
	while (idx /= 2) {
		arr[idx] = arr[idx * 2] + arr[idx * 2 + 1];
	}
}

ll query(int l, int r, int nodeNum, int nodeL, int nodeR) {
	if (r < nodeL || nodeR < l) return 0;
	if (l <= nodeL && nodeR <= r) return arr[nodeNum];

	int mid = (nodeL + nodeR) / 2;

	return query(l, r, nodeNum * 2, nodeL, mid) + query(l, r, nodeNum * 2 + 1, mid + 1, nodeR);
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
		arr[i] = arr[i * 2] + arr[i * 2 + 1];
	}


	for (int i = 0; i < m + k; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(b, c);
		}
		else if (a == 2) {
			cout << query(b, c, 1, 1, sq) << '\n';
		}
	}

	return 0;
}