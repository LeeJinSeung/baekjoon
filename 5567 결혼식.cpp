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

vector<int> v[501];
int n, m, cnt;
bool visit[501];


int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);


	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < v[1].size(); i++) {
		int& next = v[1][i];
		for (int j = 0; j < v[next].size(); j++) {
			int& cur = v[next][j];
			if (!visit[cur]) {
				visit[cur] = true;
				cnt++;
			}
		}

		if (!visit[next]) {
			visit[next] = true;
			cnt++;
		}
	}

	cout << cnt - 1;

	return 0;
}