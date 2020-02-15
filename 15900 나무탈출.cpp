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

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, a, b;
vector<int> v[500001];
int par[500001];
int depth[500001];
bool visit[500001];
vector<int> leaf;
int res;

void dfs(int c, int p) {
	par[c] = p;
	depth[c] = depth[p] + 1;
	visit[c] = true;

	int size = 0;

	for (int i = 0; i < v[c].size(); i++) {
		int &next = v[c][i];
		if (!visit[next]) {
			size++;
			dfs(next, c);
		}
	}
	if (size == 0) leaf.push_back(c);
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	memset(depth, -1, sizeof(depth));

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1, 0);

	for (int i = 0; i < leaf.size(); i++) {
		res += depth[leaf[i]];
	}

	if (res % 2 == 0) cout << "No";
	else cout << "Yes";


	return 0;
}