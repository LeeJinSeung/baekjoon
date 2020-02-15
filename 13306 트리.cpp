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

struct query {
	int x;
	int a;
	int b;
	query(int xx, int aa, int bb) {
		x = xx;
		a = aa;
		b = bb;
	}
};

const int MAX = 2 * 1e5 + 1;

int n, q, x, a, b, cur;
int par[MAX];
int uf[MAX];
vector<query> v;
stack<int> st;

int find(int n) {
	if (uf[n] == n) return n;
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

	cin >> n >> q;
	for (int i = 2; i <= n; i++) cin >> par[i];

	for (int i = 1; i <= n; i++) uf[i] = i;


	for (int i = 1; i < n + q; i++) {
		cin >> x;
		if (x == 0) {
			cin >> a;
			b = -1;;
		}
		else if (x == 1) {
			cin >> a >> b;
		}
		v.push_back(query(x, a, b));
	}

	for (int i = v.size() - 1; i >= 0; i--) {
		x = v[i].x;
		a = v[i].a;
		b = v[i].b;

		if (x == 0) {
			merge(a, par[a]);
		}
		else if (x == 1) {
			a = find(a);
			b = find(b);
			if (a != b) st.push(0);
			else st.push(1);
		}
	}

	while (!st.empty()) {
		cur = st.top();
		st.pop();
		if (cur == 0) cout << "NO\n";
		else if (cur == 1) cout << "YES\n";
	}

	return 0;
}