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

const int INF = 987654321;

int n, m, s, e;
vector<pii> v[1001];
int dist[1001];
bool visit[1001];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(pii(b, c));
	}
	cin >> s >> e;

	for (int i = 0; i < 1001; i++) dist[i] = INF;

	dist[s] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(pii(0, s));

	while (!pq.empty()) {
		int cur;
		do {
			cur = pq.top().second;
			pq.pop();
		} while (!pq.empty() && visit[cur]);

		if (visit[cur]) break;

		visit[cur] = true;
		for (auto &p : v[cur]) {
			int next = p.first, d = p.second;
			if (dist[next] > dist[cur] + d) {
				dist[next] = dist[cur] + d;
				pq.push(pii(dist[next], next));
			}
		}
	}
	cout << dist[e];

	return 0;
}