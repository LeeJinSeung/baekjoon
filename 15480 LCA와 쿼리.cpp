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

const int MAX = 100001;

vector<int> v[MAX];
int depth[MAX];
int anc[MAX][18];
int n, m, a, b, c, x, y, z;

void dfs(int cur, int par) {
	depth[cur] = depth[par] + 1;
	anc[cur][0] = par;

	for (int i = 0; i < v[cur].size(); i++) {
		int& next = v[cur][i];

		if (par != next) dfs(next, cur);

	}
}

void func() {
	for (int i = 1; i < 18; i++) {
		for (int j = 2; j <= n; j++) {
			if (anc[j][i - 1] != 0) {
				anc[j][i] = anc[anc[j][i - 1]][i - 1];
			}
		}
	}
}

int lca(int a, int b) {
	if (depth[a] > depth[b]) swap(a, b);

	if (depth[a] == 0) return a;

	int diff = depth[b] - depth[a];

	for (int i = 17; diff; i--) {
		if (diff / (1 << i)) {
			diff %= (1 << i);
			b = anc[b][i];
		}
	}

	if (a != b) {
		int l = 0;
		for (int i = 17; i >= 0; i--) {
			if (anc[a][i] != 0 && anc[b][i] != 0) {
				if (anc[a][i] == anc[b][i]) l = anc[a][i];
				else {
					a = anc[a][i];
					b = anc[b][i];
				}
			}
		}
		return l;
	}
	else return a;
}



int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	memset(depth, -1, sizeof(depth));
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1, 0);
	func();

	cin >> m;
	while (m--) {
		cin >> a >> b >> c;
		x = lca(a, b);
		y = lca(a, c);
		z = lca(b, c);

		x = depth[x] > depth[y] ? x : y;
		x = depth[x] > depth[z] ? x : z;
		cout << x << '\n';
	}

	return 0;
}