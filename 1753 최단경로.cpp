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

const int INF = 987654321;

int v, e, s, a, b, c;
vector<pii> g[20001];
int dist[20001];
bool visit[20001];
priority_queue<pii, vector<pii>, greater<pii>> pq;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> v >> e >> s;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		g[a].push_back(pii(b, c));
	}
	for (int i = 1; i <= v; i++) {
		dist[i] = INF;
	}

	dist[s] = 0;
	pq.push(pii(0, s));
	while (!pq.empty()) {
		int cur;
		do {
			cur = pq.top().second;
			pq.pop();
		} while (!pq.empty() && visit[cur]);

		if (visit[cur]) break;

		visit[cur] = true;
		for (auto &p : g[cur]) {
			int next = p.first, d = p.second;

			if (dist[next] > dist[cur] + d) {
				dist[next] = dist[cur] + d;
				pq.push(pii(dist[next], next));
			}
		}
	}

	for (int i = 1; i <= v; i++) {
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << '\n';
	}

	return 0;
}