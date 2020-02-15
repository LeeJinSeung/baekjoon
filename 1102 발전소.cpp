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

int n, state, p, cnt;
int arr[16][16];
int dp[1 << 17];
string str;

int func(int state) {
	int &ret = dp[state];
	if (ret != -1) return ret;
	if (cnt >= p) return 0;

	ret = INF;
	cnt++;

	for (int i = 0; i < n; i++) {
		if (state & (1 << i)) {
			for (int j = 0; j < n; j++) {
				if (!(state & (1 << j)))
					ret = min(ret, func(state | (1 << j)) + arr[i][j]);
			}
		}
	}
	cnt--;
	return ret;
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	memset(dp, -1, sizeof(dp));

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'Y') {
			state |= (1 << i);
			cnt++;
		}
	}
	cin >> p;

	int res = func(state);

	if (res == INF) cout << -1;
	else cout << res;


	return 0;
}