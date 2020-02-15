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

int n, m;
int o, p;
vector<int> v[11];
int visit[11];
int cnt, choice, minCnt;

void dfs(int idx) {
	if (cnt == n) {
		if (minCnt > choice) minCnt = choice;
	}
	if (idx == m + 1) return;


	for (int i = 0; i < v[idx].size(); i++) {
		int t = v[idx][i];
		if (visit[t] == 0) cnt++;

		visit[t]++;
	}
	choice++;
	dfs(idx + 1);

	for (int i = 0; i < v[idx].size(); i++) {
		int t = v[idx][i];
		visit[t]--;
		if (visit[t] == 0) cnt--;
	}
	choice--;
	dfs(idx + 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> o;
		for (int j = 0; j < o; j++) {
			cin >> p;
			v[i].push_back(p);
		}
	}
	minCnt = INF;
	dfs(1);

	if (minCnt == INF) cout << -1;
	else {
		cout << minCnt;
	}


	return 0;
}