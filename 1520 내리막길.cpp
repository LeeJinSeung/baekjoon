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

int n, m;
int arr[501][501];
int dp[501][501];
int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,1,-1 };

bool exist(int r, int c) {
	if (r > 0 && c > 0 && r <= n && c <= m) return true;
	else return false;
}


int func(int r, int c) {
	if (r == 1 && c == 1) return 1;

	int& ret = dp[r][c];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (!exist(nr, nc)) continue;
		if (arr[r][c] < arr[nr][nc]) ret += func(nr, nc);
	}

	return ret;
}


int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	memset(dp, -1, sizeof(dp));
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}

	cout << func(n, m);


	return 0;
}