#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>
#include <string>
#include <cstring>
#include <functional>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int INF = 1000000001;

int n, m;
int a, b, c;
int s, e;
vector<pii> v[100001];
queue<int> q;
bool visit[100001];

bool bfs(int s, int e, int l) {
	memset(visit, 0, sizeof(visit));
	q.push(s);
	visit[s] = true;
	while (!q.empty()) {
		int cur = q.front();
		// int wei = q.front().second;
		q.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int nextW = v[cur][i].second;

			if (!visit[next] && nextW >= l) {
				visit[next] = true;
				q.push(next);
			}
		}
	}

	return visit[e];
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	int mx = -1;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		mx = max(mx, c);
		v[a].push_back(pii(b, c));
		v[b].push_back(pii(a, c));
	}

	cin >> s >> e;
	int l = 1;
	int r = mx;
	int res = 0;

	while (l <= r) {
		int mid = (l + r) / 2;

		if (bfs(s, e, mid)) {
			if (res < mid) res = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}

	cout << res;

	return 0;
}