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

int n, m, x;
int uf[201];
int arr[201][201];
vector<int> v;
bool f;

int find(int n) {
	if (uf[n] == n) return n;
	return uf[n] = find(uf[n]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	uf[b] = a;
}



int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	for (int i = 1; i <= 200; i++) uf[i] = i;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) merge(i, j);
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> x;
		v.push_back(x);
	}

	int from = 0;
	for (int i = 1; i < v.size(); i++) {
		if (find(v[from]) != find(v[i])) {
			f = true;
			break;
		}
		from = i;
	}


	if (f) cout << "NO";
	else cout << "YES";

	return 0;
}