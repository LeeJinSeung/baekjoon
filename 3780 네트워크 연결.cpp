#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

const int MAX = 20001;

int uf[MAX];
ll dist[MAX];
int t, n, a, b;
char c;

int find(int n) {
	if (uf[n] < 0) return n;
	int tmp = find(uf[n]);
	dist[n] += dist[uf[n]];
	uf[n] = tmp;
	return tmp;
}

void merge(int a, int b) {
	a = find(a);
	if (a != b) {
		uf[a] = b;
		dist[a] = abs(b - a) % 1000;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		memset(uf, -1, sizeof(uf));
		memset(dist, 0, sizeof(dist));
		while (1) {
			cin >> c;
			if (c == 'O') break;
			else if (c == 'E') {
				cin >> a;
				find(a);
				cout << dist[a] << '\n';
			}
			else if (c == 'I') {
				cin >> a >> b;
				merge(a, b);
			}
		}
	}




	return 0;
}