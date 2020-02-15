#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 1001;

int uf[MAX];
int e[MAX];
int n, m, a, b, fa, fb, cnt;
char c;

int find(int n) {
	if (n == uf[n]) return n;
	return uf[n] = find(uf[n]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) uf[b] = a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) uf[i] = i;
	while (m--) {
		cin >> c >> a >> b;
		fa = find(a);
		fb = find(b);
		if (c == 'E') {
			if (e[a]) merge(fb, e[a]);
			if (e[b]) merge(fa, e[b]);
			e[b] = fa;
			e[a] = fb;
		}
		else if (fa != fb) {
			merge(fa, fb);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (uf[i] == i) cnt++;
	}
	cout << cnt;



	return 0;
}