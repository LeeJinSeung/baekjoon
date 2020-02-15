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

const int MAX = 100001;

int uf[10001];
int arr[10001];
pip edge[MAX];
vector<pip> v;


int find(int n) {
	if (uf[n] < 0) return n;
	return uf[n] = find(uf[n]);
}

bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	if (uf[a] > uf[b]) swap(a, b);
	uf[a] += uf[b];
	uf[b] = a;
	return true;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(uf, -1, sizeof(uf));
	cin >> n >> m;

	sum = 1001;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum = min(sum, arr[i]);
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		edge[i].first = c * 2 + arr[a] + arr[b];
		edge[i].second.first = a;
		edge[i].second.second = b;
	}

	sort(edge, edge + m);

	for (int i = 0; i < m; i++) {
		a = edge[i].first;
		b = edge[i].second.first;
		c = edge[i].second.second;


		if (merge(b, c)) {
			sum += a;
			if (++cnt == n - 1) break;
		}
	}
	cout << sum;


	return 0;
}