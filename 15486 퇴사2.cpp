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

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n;
pii arr[1500001];
int dp[1500001];

int func(int pos) {
	if (pos == n + 1) return 0;
	if (pos > n + 1) return -987654321;

	int &ret = dp[pos];
	if (ret != -1) return ret;
	ret = max(func(pos + 1), func(pos + arr[pos].first) + arr[pos].second);
	return ret;
}


int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	cout << func(1);


	return 0;
}