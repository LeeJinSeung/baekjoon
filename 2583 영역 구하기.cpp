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

int n, m, k, cnt;
int arr[102][102];
bool visit[102][102];
int dr[] = { 1,-1,0,0 };
int dc[] = { 0,0,1,-1 };

priority_queue<int, vector<int>, greater<int>> pq;

bool exist(int r, int c) {
	if (r < 0 || c < 0 || r >= n || c >= m) return false;
	else return true;
}

void dfs(int r, int c) {
	visit[r][c] = true;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (exist(nr, nc)) {
			if (!visit[nr][nc] && arr[nr][nc] == 0) {
				dfs(nr, nc);
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int i = a; i < c; i++) {
			for (int j = b; j < d; j++) {
				arr[j][i]++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visit[i][j] && arr[i][j] == 0) {
				cnt = 0;
				dfs(i, j);
				pq.push(cnt);
			}

		}
	}
	cout << pq.size() << '\n';
	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}

	return 0;
}