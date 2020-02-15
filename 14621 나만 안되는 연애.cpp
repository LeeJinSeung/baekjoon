#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pip;

int n, m, a, b, c, cnt, sum;

char arr[1001];
int uf[1001];
pip edge[10001];


int find(int n) {
	if (uf[n] < 0) return n;
	return uf[n] = find(uf[n]);
}

bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	uf[b] = a;
	return true;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(uf, -1, sizeof(uf));
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 0; i < m; i++)
		cin >> edge[i].second.first >> edge[i].second.second >> edge[i].first;

	sort(edge, edge + m);

	for (int i = 0; i < m; i++) {
		a = edge[i].first;
		b = edge[i].second.first;
		c = edge[i].second.second;

		if (arr[b] != arr[c]) {
			if (merge(b, c)) {
				sum += a;
				if (++cnt == n - 1) break;
			}
		}
	}

	if (cnt == n - 1) cout << sum;
	else cout << -1;


	return 0;
}