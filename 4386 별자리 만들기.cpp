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
typedef pair<double, double> pdd;
typedef pair<double, pii> pdp;


const int MAX = 50 * 101;

int n, m, b, c, cnt;
double res, a;

vector<pdp> v;
int uf[10001];
pdd p[101];

double cal(pdd& a, pdd& b) {
	return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

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
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);


	cout << fixed;
	cout.precision(2);
	cin >> n;
	memset(uf, -1, sizeof(uf));

	for (int i = 1; i <= n; i++) cin >> p[i].first >> p[i].second;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			v.push_back({ cal(p[i], p[j]),{ i,j } });
		}
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		a = v[i].first;
		b = v[i].second.first;
		c = v[i].second.second;

		if (merge(b, c)) {
			res += a;
			if (++cnt == n - 1) break;
		}
	}

	cout << res;

	return 0;
}