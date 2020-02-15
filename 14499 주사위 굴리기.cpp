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

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, m, x, y, k, a;
int map[20][20];
int dice[7];
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,-1,1 };

bool safe(int r, int c) {
	if (r >= 0 && c >= 0 && r < n && c < m) return true;
	else return false;
}

void func(int a) {
	int tmp[7];
	for (int i = 0; i < 7; i++) tmp[i] = dice[i];

	int nx = x + dx[a];
	int ny = y + dy[a];

	if (!safe(nx, ny)) return;

	if (a == 0) {
		dice[1] = tmp[4];
		dice[3] = tmp[1];
		dice[4] = tmp[6];
		dice[6] = tmp[3];
	}
	else if (a == 1) {
		dice[1] = tmp[3];
		dice[3] = tmp[6];
		dice[4] = tmp[1];
		dice[6] = tmp[4];
	}
	else if (a == 2) {
		dice[1] = tmp[5];
		dice[2] = tmp[1];
		dice[5] = tmp[6];
		dice[6] = tmp[2];
	}
	else if (a == 3) {
		dice[1] = tmp[2];
		dice[2] = tmp[6];
		dice[5] = tmp[1];
		dice[6] = tmp[5];
	}
	if (map[nx][ny] == 0) map[nx][ny] = dice[6];
	else {
		dice[6] = map[nx][ny];
		map[nx][ny] = 0;
	}
	x = nx;
	y = ny;
	cout << dice[1] << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		cin >> a;
		a--;
		func(a);
	}



	return 0;
}