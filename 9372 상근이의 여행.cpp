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


const int MAX = 1e4;

int t, n, m, a, b;


int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> n >> m;

		for (int i = 0; i < m; i++) cin >> a >> b;
		cout << n - 1 << '\n';
	}

	return 0;
}