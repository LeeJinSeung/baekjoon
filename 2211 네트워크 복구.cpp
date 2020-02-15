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
typedef pair<ll, pii> pip;

const int MAX = 1e3 + 1;

int n, m, a, b, c;
vector<pii> v[MAX];
priority_queue<pip> pq;
vector<pii> res;
int dp[MAX];


int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);


	memset(dp, -1, sizeof(dp));
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		v[a].push_back(pii(b, c));
		v[b].push_back(pii(a, c));
	}

	pq.push({ 0,{ 1,0 } });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second.first;
		int par = pq.top().second.second;
		pq.pop();

		if (dp[cur] != -1) continue;
		dp[cur] = cost;
		if (par) res.push_back(pii(cur, par));

		for (auto next : v[cur]) {
			int tmp = next.first;
			if (dp[tmp] != -1) continue;
			pq.push({ -cost - next.second,{ tmp, cur } });
		}
	}

	cout << res.size() << '\n';
	for (auto a : res)
		cout << a.first << " " << a.second << '\n';

	return 0;
}