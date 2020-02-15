#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1000000;

vector<pii> tree[100001];
int depth[100001];
bool visit[100001];
int par[100001][18];
int mn[100001][18];
int mx[100001][18];

int n, a, b, c, k, mindis, maxdis;

void dfs(int pre, int cur, int w) {
	visit[cur] = true;
	par[cur][0] = pre;
	mn[cur][0] = w;
	mx[cur][0] = w;
	depth[cur] = depth[pre] + 1;

	for (int i = 0; i < tree[cur].size(); i++) {
		int next = tree[cur][i].first;
		int nextW = tree[cur][i].second;
		if (!visit[next]) {
			dfs(cur, next, nextW);
		}
	}
}

void lca(int a, int b) {

	if (depth[a] < depth[b]) {
		int tmp = a;
		a = b;
		b = tmp;
	}

	int diff = depth[a] - depth[b];


	for (int i = 0; diff; i++) {
		if (diff % 2) {
			mindis = min(mindis, mn[a][i]);
			maxdis = max(maxdis, mx[a][i]);
			a = par[a][i];
		}
		diff /= 2;
	}
	if (a != b) {
		for (int i = 17; i >= 0; i--) {
			if (par[a][i] != -1 && par[b][i] != par[a][i]) {
				int maxd = max(mx[a][i], mx[b][i]);
				int mind = min(mn[a][i], mn[b][i]);
				mindis = min(mindis, mind);
				maxdis = max(maxdis, maxd);
				a = par[a][i];
				b = par[b][i];
			}
		}


		int x = max(mx[a][0], mx[b][0]);
		int n = min(mn[a][0], mn[b][0]);

		mindis = min(mindis, n);
		maxdis = max(maxdis, x);

	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(par, -1, sizeof(par));
	memset(depth, -1, sizeof(depth));

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> c;
		tree[a].push_back(pii(b, c));
		tree[b].push_back(pii(a, c));
	}

	dfs(-1, 1, 0);

	for (int i = 0; i < 17; i++) {
		for (int j = 1; j <= n; j++) {
			if (par[j][i] != -1) {
				if (mx[j][i] != 0 && mx[par[j][i]][i] != 0)
					mx[j][i + 1] = max(mx[j][i], mx[par[j][i]][i]);
				if (mn[j][i] != 0 && mn[par[j][i]][i] != 0)
					mn[j][i + 1] = min(mn[j][i], mn[par[j][i]][i]);
				par[j][i + 1] = par[par[j][i]][i];

			}
		}
	}

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		mindis = MAX;
		maxdis = 0;
		lca(a, b);

		cout << mindis << " " << maxdis << '\n';
	}

	return 0;
}