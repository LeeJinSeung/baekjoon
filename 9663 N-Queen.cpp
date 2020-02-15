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

int n, cnt, res;
bool r[30];
bool ld[30];
bool ru[30];

void dfs(int cur) {
	if (cur == n) {
		res++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!r[i] && !ld[cur + i] && !ru[cur - i + n - 1]) {
			r[i] = ld[cur + i] = ru[cur - i + n - 1] = true;
			dfs(cur + 1);
			r[i] = ld[cur + i] = ru[cur - i + n - 1] = false;
		}

	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	dfs(0);
	cout << res;


	return 0;
}