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

const int INF = -987654321;

int c;
int arr[11][11];
int dp[12][1 << 12];


int func(int cur, int state) {
	if (state == (1 << 11) - 1) return 0;

	int& ret = dp[cur][state];
	if (ret != -1) return ret;
	ret = INF;
	for (int i = 0; i < 11; i++) {
		if ((state & (1 << i)) != 0) continue;
		if (arr[cur][i] == 0) continue;
		ret = max(ret, func(cur + 1, state | (1 << i)) + arr[cur][i]);
	}
	return ret;
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> c;
	while (c--) {

		for (int i = 0; i < 11; i++)
			for (int j = 0; j < 11; j++)
				cin >> arr[i][j];

		memset(dp, -1, sizeof(dp));

		cout << func(0, 0) << '\n';
	}

	return 0;
}