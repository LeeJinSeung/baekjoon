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

int n;
int arr[16][16];
int dp[17][1 << 17];
int dx;

int func(int cur, int state) {
	if (state == ((1 << n) - 1)) {
		if (arr[cur][dx] == 0) return INF;
		return arr[cur][dx];
	}

	int &ret = dp[cur][state];
	if (ret != -1) return ret;
	ret = INF;
	for (int i = 0; i < n; i++) {
		if ((state & (1 << i)) != 0) continue;
		if (arr[cur][i] == 0) continue;
		ret = min(ret, func(i, state | (1 << i)) + arr[cur][i]);
	}
	return ret;
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	memset(dp, -1, sizeof(dp));

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	cout << func(0, 1 << 0);

	return 0;
}