#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


struct Point {
	double x, y;
	int idx;
	Point() {
		x = y = 0;
	}
	Point(double xx, double yy, int i) {
		x = xx;
		y = yy;
		idx = i;
	}
};

struct Edge {
	double dis;
	int u, v;
	Edge() {
		u = v = dis = 0;
	}
	Edge(int uu, int vv, double d) {
		dis = d;
		u = uu;
		v = vv;
	}
	bool operator < (const Edge& e) {
		return dis < e.dis;
	}
};

int n, m, a, b, c, cnt, idx;
double sum, d;

const int MAXV = 1001;
const int MAXE = MAXV * (MAXV + 1) / 2;

int uf[MAXV];
Point p[MAXV];
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

bool cmpx(Point a, Point b) {
	return a.x < b.x;
}

bool cmpy(Point a, Point b) {
	return a.y < b.y;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(uf, -1, sizeof(uf));
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> p[i].x >> p[i].y;
		p[i].idx = i;
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		merge(a, b);
	}

	sort(p + 1, p + n + 1, cmpx);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			edge[idx].u = p[i].idx;
			edge[idx].v = p[j].idx;
			edge[idx++].dis = sqrt((p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y));
		}
	}


	sort(edge, edge + idx);

	for (int i = 0; i < idx; i++) {
		d = edge[i].dis;
		b = edge[i].u;
		c = edge[i].v;

		if (merge(b, c)) {
			sum += d;
			if (++cnt == n - m - 1) break;
		}
	}

	cout.precision(2);
	cout << fixed;
	cout << sum;

	return 0;
}