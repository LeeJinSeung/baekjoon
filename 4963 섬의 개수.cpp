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

int n, m, cnt;
int arr[52][52];
bool visit[52][52];
int dr[8] = { 0,0,1,1,1,-1,-1,-1 };
int dc[8] = { 1,-1,0,1,-1,0,1,-1 };

void dfs(int r, int c) {
	visit[r][c] = true;
	for (int i = 0; i < 8; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (!visit[nr][nc] && arr[nr][nc] == 1) dfs(nr, nc);
	}
}


int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	while (n != 0 || m != 0) {
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> arr[i][j];
			}
		}

		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][j] == 1 && !visit[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}
		}



		cout << cnt << '\n';
		cnt = 0;
		memset(visit, 0, sizeof(visit));
		memset(arr, 0, sizeof(arr));
		cin >> n >> m;
	}

}