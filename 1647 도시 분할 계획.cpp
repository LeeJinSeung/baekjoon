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
typedef pair<ll, pii> pip;


const int MAX = 1e6;

int n, m, a, b, c, cnt, mx;
ll res;

pip arr[MAX];
int uf[100001];

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

	for (int i = 0; i < m; i++)
		cin >> arr[i].second.first >> arr[i].second.second >> arr[i].first;


	sort(arr, arr + m);

	for (int i = 0; i < m; i++) {
		a = arr[i].first;
		b = arr[i].second.first;
		c = arr[i].second.second;

		if (merge(b, c)) {
			res += a;
			mx = max(mx, a);
			if (++cnt == n - 1) break;
		}
	}

	cout << res - mx;

	return 0;
}