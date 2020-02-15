#include <iostream>
#include <cstring>

using namespace std;


const int MAX = 300000 + 1;

int uf[MAX];
bool full[MAX], drink[MAX];
int n, l, a, b, c;

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

	cin >> n >> l;
	for (int i = 1; i <= l; i++) uf[i] = i;

	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		if (!full[a]) {
			full[a] = true;
			merge(b, a);
			continue;
		}
		if (!full[b]) {
			full[b] = true;
			merge(a, b);
			continue;
		}
		c = find(a);
		if (!full[c]) {
			full[c] = true;
			merge(a, c);
			merge(b, a);
			continue;
		}

		c = find(b);
		if (!full[c]) {
			full[c] = true;
			merge(b, c);
			merge(a, b);
			continue;
		}
		drink[i] = true;
	}
	for (int i = 1; i <= n; i++) {
		if (drink[i]) cout << "SMECE\n";
		else cout << "LADICA\n";
	}


	return 0;
}