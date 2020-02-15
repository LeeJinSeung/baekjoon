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

const int MAX = 2000000;

int n, a, b;
int tree[4 * MAX + 1];

int update(int val, int l, int r, int node, int ch) {
	if (l > ch || r < ch) return tree[node];
	if (l == r) return tree[node] += val;

	int mid = (l + r) / 2;
	return tree[node] = update(val, l, mid, node * 2, ch) + update(val, mid + 1, r, node * 2 + 1, ch);
}

int query(int val, int l, int r, int node) {
	if (l == r) return l;

	int mid = (l + r) / 2;
	if (tree[node * 2] < val) return query(val - tree[node * 2], mid + 1, r, node * 2 + 1);
	return query(val, l, mid, node * 2);
}


int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;

		if (a == 1) {
			update(1, 1, MAX, 1, b);
		}
		else if (a == 2) {
			int ret = query(b, 1, MAX, 1);
			cout << ret << '\n';
			update(-1, 1, MAX, 1, ret);
		}

		
	}

	return 0;
}