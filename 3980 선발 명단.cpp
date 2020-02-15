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

const int INF = 987654321;

int res, c;
int arr[11][11];
bool visit[11];

void func(int cur, int sum) {
	if (cur == 11) {
		res = max(res, sum);
		return;
	}
	for (int i = 0; i < 11; i++) {
		if (arr[cur][i] != 0 && !visit[i]) {
			visit[i] = true;
			func(cur + 1, sum + arr[cur][i]);
			visit[i] = false;
		}
	}
}

void solve() {
	for (int i = 0; i < 11; i++) {
		if (arr[0][i] != 0) {
			visit[i] = true;
			func(1, arr[0][i]);
			visit[i] = false;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> c;
	while (c--) {


		for (int i = 0; i < 11; i++)
			for (int j = 0; j < 11; j++)
				cin >> arr[i][j];

		func(0, 0);
		cout << res << '\n';
		res = 0;
	}

	return 0;
}