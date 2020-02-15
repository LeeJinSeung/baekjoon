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
	int x, y, z, idx;
	Point() {
		x = y = z = idx = 0;
	}
	Point(int xx, int yy, int zz, int i) {
		x = xx;
		y = yy;
		z = zz;
		idx = i;
	}
};

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
ll sum;

const int MAX = 100001;

int uf[MAX];
Point arr[MAX];
Edge edge[3 * MAX];

bool cmpx(Point a, Point b) {
	return a.x < b.x;
}
bool cmpy(Point a, Point b) {
	return a.y < b.y;
}
bool cmpz(Point a, Point b) {
	return a.z < b.z;
}


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
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i].x >> arr[i].y >> arr[i].z;
		arr[i].idx = i;
	}

	sort(arr, arr + n, cmpx);

	for (int i = 0; i < n - 1; i++) {
		edge[idx].u = arr[i].idx;
		edge[idx].v = arr[i + 1].idx;
		edge[idx++].dis = abs(arr[i].x - arr[i + 1].x);
	}

	sort(arr, arr + n, cmpy);

	for (int i = 0; i < n - 1; i++) {
		edge[idx].u = arr[i].idx;
		edge[idx].v = arr[i + 1].idx;
		edge[idx++].dis = abs(arr[i].y - arr[i + 1].y);
	}

	sort(arr, arr + n, cmpz);

	for (int i = 0; i < n - 1; i++) {
		edge[idx].u = arr[i].idx;
		edge[idx].v = arr[i + 1].idx;
		edge[idx++].dis = abs(arr[i].z - arr[i + 1].z);
	}


	sort(edge, edge + idx);

	for (int i = 0; i < idx; i++) {
		a = edge[i].dis;
		b = edge[i].u;
		c = edge[i].v;

		if (merge(b, c)) {
			sum += a;
			if (++cnt == n - 1) break;
		}
	}
	cout << sum;





	return 0;
}