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

int t, w, res;
int dp[1010][33][3];
int arr[1001][3];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> t >> w;

	for (int i = 1; i <= t; i++) {
		int a;
		cin >> a;
		arr[i][a] = 1;
	}

	dp[1][0][1] = arr[1][1];
	dp[1][1][2] = arr[1][2];

	for (int i = 2; i <= t; i++) {
		for (int j = 0; j <= w; j++) {
			dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][2]) + arr[i][1];
			dp[i][j][2] = max(dp[i - 1][j][2], dp[i - 1][j - 1][1]) + arr[i][2];
			res = max(res, max(dp[i][j][1], dp[i][j][2]));
		}
	}



	cout << res;

	return 0;
}