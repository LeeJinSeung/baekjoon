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

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 987654321;

struct Point {
	int r;
	int c;
	int t;

	Point(int rr, int cc, int tt) {
		r = rr;
		c = cc;
		t = tt;
	}

	const bool operator<(const Point& p) {
		if (t == p.t) {
			if (r == p.r) return c > p.c;
			return r > p.r;
		}
		return t > p.t;
	}
};

struct Shark {
	int r;
	int c;
	int cnt = 0;
	int size = 2;
	Shark() {
		r = 0;
		c = 0;
	}
	Shark(int rr, int cc) {
		r = rr;
		c = cc;
	}
	void increase() {
		cnt = 0;
		size++;
	}
};

int n, res;
Shark s;
int arr[22][22];
bool visit[22][22];
int dr[4] = { -1,0,0,1 };
int dc[4] = { 0,-1,1,0 };

void bfs() {
	priority_queue<Point> pq;
	pq.push(Point(s.r, s.c, 0));
	visit[s.r][s.c] = true;

	while (!pq.empty()) {
		Point cur = pq.top();
		pq.pop();

		if (arr[cur.r][cur.c] != 0 && s.size > arr[cur.r][cur.c]) {
			s.r = cur.r;
			s.c = cur.c;
			s.cnt++;
			arr[cur.r][cur.c] = 0;
			if (s.cnt == s.size) s.increase();

			memset(visit, 0, sizeof(visit));
			while (!pq.empty()) pq.pop();
			res = cur.t;
		}

		for (int i = 0; i < 4; i++) {
			int nr = cur.r + dr[i];
			int nc = cur.c + dc[i];
			if (!visit[nr][nc] && arr[nr][nc] <= s.size) {
				visit[nr][nc] = true;
				pq.push(Point(nr, nc, cur.t + 1));
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 22; i++) {
		for (int j = 0; j < 22; j++) {
			arr[i][j] = MAX;
		}
	}

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				s.r = i;
				s.c = j;
				arr[i][j] = 0;
			}
		}
	}
	bfs();

	cout << res;


	return 0;
}