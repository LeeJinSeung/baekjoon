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

int arr[10][10];
int paper[6];
int res;

bool func(int r, int c, int size) {
	if (r + size > 10 || c + size > 10) return false;

	for (int i = r; i < r + size; i++) {
		for (int j = c; j < c + size; j++) {
			if (arr[i][j] == 0) return false;
		}
	}
	return true;
}

void fillPaper(int r, int c, int size, bool f) {
	for (int i = r; i < r + size; i++) {
		for (int j = c; j < c + size; j++) {
			if (f) arr[i][j] = 0;
			else arr[i][j] = 1;
		}
	}
}


void dfs(int cnt) {
	if (cnt >= res) return;
	bool flag = false;

	pii p = pii(10, 10);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (arr[i][j]) {
				p = pii(i, j);
				flag = true;
				break;
			}
		}
		if (flag) break;
	}


	if (flag) {
		for (int i = 1; i <= 5; i++) {
			if (paper[i] == 5) continue;
			else {
				if (func(p.first, p.second, i)) {
					fillPaper(p.first, p.second, i, true);
					paper[i]++;
					dfs(cnt + 1);
					fillPaper(p.first, p.second, i, false);
					paper[i]--;
				}
				else break;
			}
		}
	}
	else res = min(res, cnt);
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) {
			cin >> arr[i][j];
		}

	res = 26;
	dfs(0);


	if (res == 26) cout << "-1\n";
	else cout << res << '\n';

	return 0;
}