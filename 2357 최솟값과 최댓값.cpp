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

int n, m, a, b, sq;
int maxST[400001];
int minST[400001];

void init() {
	sq = 1;
	while (sq < n)
		sq *= 2;
}

int calMax(int l, int r, int nodeNum, int nodeL, int nodeR) {
	if (r < nodeL || nodeR < l) return 0;
	if (l <= nodeL && nodeR <= r) return maxST[nodeNum];
	int mid = (nodeL + nodeR) / 2;
	return max(calMax(l, r, nodeNum * 2, nodeL, mid), calMax(l, r, nodeNum * 2 + 1, mid + 1, nodeR));
}

int calMin(int l, int r, int nodeNum, int nodeL, int nodeR) {
	if (r < nodeL || nodeR < l) return MAX;
	if (l <= nodeL && nodeR <= r) return minST[nodeNum];
	int mid = (nodeL + nodeR) / 2;
	return min(calMin(l, r, nodeNum * 2, nodeL, mid), calMin(l, r, nodeNum * 2 + 1, mid + 1, nodeR));
}


int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	init();

	for (int i = 0; i < n; i++) {
		cin >> maxST[sq + i];
		minST[sq + i] = maxST[sq + i];
	}

	for (int i = sq - 1; i > 0; i--) {
		minST[i] = min(minST[2 * i], minST[i * 2 + 1]);
		maxST[i] = max(maxST[2 * i], maxST[i * 2 + 1]);
	}


	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout << calMin(a, b, 1, 1, sq) << " " << calMax(a, b, 1, 1, sq) << '\n';
	}

	return 0;
}