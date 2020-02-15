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

const int MAX = 10001;

int v, e, a, b, cnt, s;
int dfsn[MAX], sn[MAX];
vector<int> adj[MAX];
bool finished[MAX];
stack<int> st;
vector<vector<int>> scc;


int dfs(int cur) {
	dfsn[cur] = ++cnt;
	st.push(cur);

	int res = dfsn[cur];
	for (int next : adj[cur]) {
		if (dfsn[next] == 0) res = min(res, dfs(next));
		else if (!finished[next]) res = min(res, dfsn[next]);
	}

	if (res == dfsn[cur]) {
		vector<int> curSCC;

		while (1) {
			int tmp = st.top();
			st.pop();
			curSCC.push_back(tmp);
			finished[tmp] = true;
			sn[tmp] = s;
			if (tmp == cur) break;
		}
		sort(curSCC.begin(), curSCC.end());
		scc.push_back(curSCC);
		s++;
	}
	return res;

}


int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> v >> e;

	for (int i = 0; i < e; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
	}

	for (int i = 1; i <= v; i++) {
		if (dfsn[i] == 0) dfs(i);
	}
	sort(scc.begin(), scc.end());

	cout << s << '\n';
	for (auto& curSCC : scc) {
		for (int cur : curSCC)
			cout << cur << ' ';
		cout << -1 << '\n';
	}

	return 0;
}