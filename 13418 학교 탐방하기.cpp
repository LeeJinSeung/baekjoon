#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct Edge {
	int dis, u, v;
	Edge() {
		u = v = dis = 0;
	}
	Edge(int uu, int vv, int d) {
		dis = d;
		u = uu;
		v = vv;
	}
	bool operator < (const Edge& e) {
		return dis < e.dis;
	}
};

int n, m, a, b, c, cnt, idx;
int minSum, maxSum;

const int MAXV = 1001;
const int MAXE = MAXV * (MAXV + 1) / 2;

int uf[MAXV];
Edge edge[MAXE];

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

	for (int i = 0; i < m + 1; i++) {
		cin >> a >> b >> c;
		edge[i].dis = 1 - c;
		edge[i].u = a;
		edge[i].v = b;
	}

	sort(edge + 1, edge + m + 1);

	if (merge(edge[0].u, edge[0].v)) {
		minSum += edge[0].dis;
	}
	for (int i = 1; i < m + 1; i++) {
		a = edge[i].dis;
		b = edge[i].u;
		c = edge[i].v;
		if (merge(b, c)) {
			minSum += a;
			if (++cnt == n - 1) break;
		}
	}


	memset(uf, -1, sizeof(uf));
	cnt = 0;

	if (merge(edge[0].u, edge[0].v)) {
		maxSum += edge[0].dis;
	}
	for (int i = m; i > 0; i--) {
		a = edge[i].dis;
		b = edge[i].u;
		c = edge[i].v;
		if (merge(b, c)) {
			maxSum += a;
			if (++cnt == n - 1) break;
		}
	}

	cout << maxSum * maxSum - minSum * minSum;





	return 0;
}