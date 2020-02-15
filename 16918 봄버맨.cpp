#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<char, int> pci;
queue<pii> q;

int r, c, n;
pci arr[200][200];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

bool func(int a, int b) {
	if (a >= 0 && a < r && b >= 0 && b < c) return true;
	else return false;
}

void bomb(int t) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j].first == '.') {
				arr[i][j].first = 'O';
			}
			else arr[i][j].second++;

			if (arr[i][j].second == 3) q.push(pii(i, j));
		}
	}

	while (!q.empty()) {
		int curr = q.front().first;
		int curc = q.front().second;
		arr[curr][curc].first = '.';
		arr[curr][curc].second = 0;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextr = curr + dy[i];
			int nextc = curc + dx[i];

			if (func(nextr, nextc)) {
				arr[nextr][nextc].first = '.';
				arr[nextr][nextc].second = 0;
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c >> n;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j].first;
			if (arr[i][j].first == 'O') {
				arr[i][j].second++;
			}
		}


	}

	for (int i = 1; i < n; i++) {
		bomb(i);
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << arr[i][j].first;
		}
		cout << '\n';
	}

	return 0;
}