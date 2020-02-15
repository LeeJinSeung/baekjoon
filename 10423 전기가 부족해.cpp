#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pip;

int n, m, a, b, c, cnt, sum, k, d;

const int MAX = 100001;

int uf[1001];
pip edge[MAX];


int find(int n) {
	if (uf[n] < 0) return -1;
	if (uf[n] == n) return n;
	return uf[n] = find(uf[n]);
}

bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	if (a == -1) uf[b] = a;
	else if (b == -1) uf[a] = b;
	else uf[b] = a;
	return true;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(uf, -1, sizeof(uf));
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) uf[i] = i;
	for (int i = 0; i < k; i++) {
		cin >> d;
		uf[d] = -1;
	}

	for (int i = 0; i < m; i++)
		cin >> edge[i].second.first >> edge[i].second.second >> edge[i].first;

	sort(edge, edge + m);

	for (int i = 0; i < m; i++) {
		a = edge[i].first;
		b = edge[i].second.first;
		c = edge[i].second.second;


		if (merge(b, c)) {
			sum += a;
			if (++cnt == n - k) break;
		}
	}
	cout << sum;


	return 0;
}