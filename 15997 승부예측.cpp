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
#include <bitset>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;

struct game {
	int x;
	int y;
	double w;
	double d;
	double l;
	game() {

	}
	game(int xx, int yy, double ww, double dd, double ll) {
		x = xx;
		y = yy;
		w = ww;
		d = dd;
		l = ll;
	}
};

game g[6];
map<string, double> m;
string a, b, s;
double w, d, l;
int score[4];
double res[4];
pii tmp[4];

void dfs(int cur, double p) {
	if (cur == 6) {
		for (int i = 0; i < 4; i++) {
			tmp[i].first = score[i];
			tmp[i].second = i;
		}
		sort(tmp, tmp + 4);


		int A = tmp[0].first, B = tmp[1].first, C = tmp[2].first, D = tmp[3].first;
		int a = tmp[0].second, b = tmp[1].second, c = tmp[2].second, d = tmp[3].second;
		if (B != C) {
			res[c] += p;
			res[d] += p;
		}
		else if (A == B && C == D) {
			res[a] += p / 2.0;
			res[b] += p / 2.0;
			res[c] += p / 2.0;
			res[d] += p / 2.0;
		}
		else if (A == B) {
			res[a] += p / 3.0;
			res[b] += p / 3.0;
			res[c] += p / 3.0;
			res[d] += p;
		}
		else if (C == D) {
			res[b] += p * 2.0 / 3.0;
			res[c] += p * 2.0 / 3.0;
			res[d] += p * 2.0 / 3.0;
		}
		else {
			res[b] += p / 2.0;
			res[c] += p / 2.0;
			res[d] += p;
		}
		return;
	}
	else {
		int curX = g[cur].x;
		int curY = g[cur].y;

		if (g[cur].w > 0) {
			score[curX] += 3;
			dfs(cur + 1, p * g[cur].w);
			score[curX] -= 3;
		}

		if (g[cur].d > 0) {
			score[curX] += 1;
			score[curY] += 1;
			dfs(cur + 1, p * g[cur].d);
			score[curX] -= 1;
			score[curY] -= 1;
		}

		if (g[cur].l > 0) {
			score[curY] += 3;
			dfs(cur + 1, p * g[cur].l);
			score[curY] -= 3;
		}

	}
}


int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cout << fixed;
	cout.precision(7);
	for (int i = 0; i < 4; i++) {
		cin >> s;
		m.insert({ s,i });
	}


	for (int i = 0; i < 6; i++) {
		cin >> a >> b >> w >> d >> l;
		g[i] = game(m[a], m[b], w, d, l);
	}

	dfs(0, 1.0);

	for (int i = 0; i < 4; i++) cout << res[i] << '\n';

	return 0;
}