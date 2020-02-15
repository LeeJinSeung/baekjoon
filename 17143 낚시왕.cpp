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

struct shark {
	int r;
	int c;
	int s;
	int d;
	int z;
	bool f;
	shark(int rr, int cc, int ss, int dd, int zz) {
		r = rr;
		c = cc;
		s = ss;
		d = dd;
		z = zz;
		f = true;
	}
};

int dr[] = { 0,-1,1,0,0 };
int dc[] = { 0,0,0,1,-1 };


int r, c, m, res;
int arr[105][105];
int tmp[105][105];
vector<shark> v;


void moveShark() {
	int rr, cc, ss, dd, zz;
	for (int i = 1; i <= m; i++) {
		if (!v[i].f) continue;

		rr = v[i].r;
		cc = v[i].c;
		ss = v[i].s;
		dd = v[i].d;
		zz = v[i].z;

		if (arr[rr][cc] == i) arr[rr][cc] = 0;

		for (int j = 0; j < ss; j++) {
			rr += dr[dd];
			cc += dc[dd];

			if (rr < 1 || cc < 1 || rr > r || cc > c) {
				if (dd == 1 || dd == 3) dd++;
				else dd--;

				rr += dr[dd];
				cc += dc[dd];

				j--;
			}
		}

		v[i].r = rr;
		v[i].c = cc;
		v[i].d = dd;

		if (arr[rr][cc] == 0) arr[rr][cc] = i;
		else if (arr[rr][cc] < i) {
			int tmp = v[arr[rr][cc]].z;
			if (zz > tmp) {
				v[arr[rr][cc]].f = false;
				arr[rr][cc] = i;
			}
			else v[i].f = false;
		}
		else arr[rr][cc] = i;
	}
}

void func() {
	for (int i = 1; i <= c; i++) {
		for (int j = 1; j <= r; j++) {
			if (arr[j][i] != 0) {
				res += v[arr[j][i]].z;
				v[arr[j][i]].f = false;
				arr[j][i] = 0;
				break;
			}
		}

		moveShark();
	}
}



int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> r >> c >> m;
	v.push_back(shark(0, 0, 0, 0, 0));

	for (int i = 1; i <= m; i++) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		arr[a][b] = i;
		v.push_back(shark(a, b, c, d, e));
	}
	func();

	cout << res;


	return 0;
}