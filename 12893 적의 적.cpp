#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 2001;

int uf[MAX];
int enemy[MAX];
int n, m, a, b, ea, eb;
bool fail;

int find(int n) {
	if (uf[n] == n) return n;
	return uf[n] = find(uf[n]);
}


bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	ea = enemy[a];
	eb = enemy[b];
	if (ea != eb) {
		uf[eb] = a;
		uf[ea] = b;
		enemy[b] = a;
		enemy[a] = b;
		return true;
	}
	return false;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		uf[i] = i;
		enemy[i] = -i;
	}
	while (m--) {
		cin >> a >> b;
		if (!merge(a, b)) fail = true;
	}
	if (fail) cout << 0;
	else cout << 1;


	return 0;
}