#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int INF = 987654321;

int n, m, x, a, b, t, maxTime;

int arr[1001][1001];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> x;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) arr[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> t;
		arr[a][b] = t; // a->b t만큰 소비
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
	}

	for (int i = 1; i <= n; i++) {
		if (maxTime < arr[x][i] + arr[i][x]) maxTime = arr[x][i] + arr[i][x];
	}
	cout << maxTime;

	return 0;
}