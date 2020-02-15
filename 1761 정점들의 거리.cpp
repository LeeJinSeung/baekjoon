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

const int MAX = 40001;

int n, m, a, b, c;

vector<pii> v[MAX];

int anc[MAX][20];
int dis[MAX];
int depth[MAX];


void dfs(int cur, int par) {
	depth[cur] = depth[par] + 1;
	anc[cur][0] = par;

	for (int i = 0; i < v[cur].size(); i++) {
		int& next = v[cur][i].first;
		int& d = v[cur][i].second;

		if (next != par) {
			dis[next] = dis[cur] + d;
			dfs(next, cur);
		}
	}
}

void func(int n) {
	for (int i = 1; i < 20; i++) {
		for (int j = 1; j <= n; j++) {
			if (anc[j][i - 1] != 0) anc[j][i] = anc[anc[j][i - 1]][i - 1];
		}
	}
}

int lca(int a, int b) {
	if (depth[a] > depth[b]) swap(a, b);

	if (depth[a] == 0) return a;

	int diff = depth[b] - depth[a];

	// depth 맞추기
	for (int i = 19; i >= 0; i--) {
		if (diff / (1 << i)) {
			diff %= (1 << i);
			b = anc[b][i];
		}
	}
	int l = 0;

	// depth가 맞춰진 상태로 lca 찾기
	if (a != b) {
		for (int i = 19; i >= 0; i--) {
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
		cin >> a >> b >> c;
		v[a].push_back(pii(b, c));
		v[b].push_back(pii(a, c));
	}
	dfs(1, 0);
	func(n);

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		int tmp = lca(a, b);
		cout << dis[a] + dis[b] - 2 * dis[tmp] << '\n';
	}


	return 0;
}