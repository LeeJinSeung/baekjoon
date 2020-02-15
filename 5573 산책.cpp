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


int h, w, n;
int x = 1, y = 1;

bool arr[1001][1001];
int dp[1005][1005];



int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> h >> w >> n;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> arr[i][j];
		}
	}
	dp[1][1] = n - 1;

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			dp[i][j + 1] += (dp[i][j] + arr[i][j]) / 2;
			dp[i + 1][j] += (dp[i][j] + !arr[i][j]) / 2;
			if (dp[i][j] % 2) arr[i][j] = !arr[i][j];
		}
	}


	while (x <= h && y <= w) arr[x][y] ? y++ : x++;

	cout << x << " " << y;

	return 0;
}