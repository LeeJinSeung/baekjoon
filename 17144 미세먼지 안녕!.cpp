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

int r, c, t, res;

int arr[55][55];
int tmp[55][55];
int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,1,-1 };
int u = -1, d;


bool exist(int rr, int cc) {
	if (rr >= 0 && rr < r && cc >= 0 && cc < c) return true;
	else return false;
}

void func() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			tmp[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] >= 5) {
				int d = arr[i][j] / 5;
				for (int k = 0; k < 4; k++) {
					int nr = i + dr[k];
					int nc = j + dc[k];
					if (exist(nr, nc) && arr[nr][nc] != -1) {
						tmp[nr][nc] += d;
						tmp[i][j] -= d;
					}
				}
			}
		}
	}

	for (int i = u - 2; i >= 0; i--) tmp[i + 1][0] = tmp[i][0];
	for (int i = 0; i < c - 1; i++) tmp[0][i] = tmp[0][i + 1];
	for (int i = 0; i < u; i++) tmp[i][c - 1] = tmp[i + 1][c - 1];
	for (int i = c - 2; i >= 0; i--) tmp[u][i + 1] = tmp[u][i];
	tmp[u][1] = 0;

	for (int i = d + 1; i<r - 1; i++) tmp[i][0] = tmp[i + 1][0];
	for (int i = 0; i<c - 1; i++) tmp[r - 1][i] = tmp[r - 1][i + 1];
	for (int i = r - 2; i >= d; i--) tmp[i + 1][c - 1] = tmp[i][c - 1];
	for (int i = c - 2; i >= 0; i--) tmp[d][i + 1] = tmp[d][i];
	tmp[d][1] = 0;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			arr[i][j] = tmp[i][j];
		}
	}

}


void solve() {
	while (t--) {
		func();
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] > 0) res += arr[i][j];
		}
	}
}


int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> r >> c >> t;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == -1) {
				if (u == -1) u = i;
				else d = i;
			}
		}
	}
	solve();

	cout << res;


	return 0;
}