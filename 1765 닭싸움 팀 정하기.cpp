#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 1001;

int arr[MAX];
int n, m, a, b, cnt;
char c;
queue<int> q;
vector<int> v[MAX];

void bfs(int root) {
	q.push(root);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int &next = v[cur][i];
			if (next > 0 && arr[next] == -1) {
				arr[next] = arr[cur];
				q.push(next);
			}
		}
	}
}

bool dfs(int prev, int cur) {
	bool f = false;
	for (int i = 0; i < v[cur].size(); i++) {
		int &next = v[cur][i];
		if (arr[-next] == -1 && next < 0) {
			f = true;
			arr[-next] = prev;
			dfs(arr[cur], -next);
		}
	}
	return f;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(arr, -1, sizeof(arr));
	cin >> n >> m;
	while (m--) {
		cin >> c >> a >> b;
		if (c == 'E') {
			v[a].push_back(-b);
			v[b].push_back(-a);
		}
		else if (c == 'F') {
			v[a].push_back(b);
			v[b].push_back(a);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (arr[i] == -1) arr[i] = ++cnt;
		cnt += dfs(cnt + 1, i);
		bfs(i);
	}
	cout << cnt;


	return 0;
}