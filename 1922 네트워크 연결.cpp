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

typedef pair<int, int> pii;
typedef pair<int, pii> pip;
typedef long long ll;

const int MAX = 100000;

int n, m, a, b, c, res, cnt;

pip arr[MAX];
int uf[1001];

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

	cin >> n >> m;
	memset(uf, -1, sizeof(uf));

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		arr[i].first = c;
		arr[i].second.first = a;
		arr[i].second.second = b;
	}

	sort(arr, arr + m);

	for (int i = 0; i < m; i++) {
		int w = arr[i].first;
		int v = arr[i].second.first;
		int u = arr[i].second.second;


		if (merge(v, u)) {
			res += w;
			if (++cnt == n - 1) break;
		}
	}

	cout << res;

	return 0;
}