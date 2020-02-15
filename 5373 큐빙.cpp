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

int t, n;
char a, b, tmp;
char cube[6][3][3]; // 0~5 위 아래 앞 뒤 왼 오

void init() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cube[0][i][j] = 'w';
			cube[1][i][j] = 'y';
			cube[2][i][j] = 'r';
			cube[3][i][j] = 'o';
			cube[4][i][j] = 'g';
			cube[5][i][j] = 'b';
		}
	}
}

void swap(int idx, char dir) {
	// 해당 면에서 가운데를 기준으로 회전
	if (dir == '+') {
		tmp = cube[idx][0][1];
		cube[idx][0][1] = cube[idx][1][0];
		cube[idx][1][0] = cube[idx][2][1];
		cube[idx][2][1] = cube[idx][1][2];
		cube[idx][1][2] = tmp;

		tmp = cube[idx][0][0];
		cube[idx][0][0] = cube[idx][2][0];
		cube[idx][2][0] = cube[idx][2][2];
		cube[idx][2][2] = cube[idx][0][2];
		cube[idx][0][2] = tmp;
	}
	else if (dir == '-') {
		tmp = cube[idx][0][1];
		cube[idx][0][1] = cube[idx][1][2];
		cube[idx][1][2] = cube[idx][2][1];
		cube[idx][2][1] = cube[idx][1][0];
		cube[idx][1][0] = tmp;

		tmp = cube[idx][0][0];
		cube[idx][0][0] = cube[idx][0][2];
		cube[idx][0][2] = cube[idx][2][2];
		cube[idx][2][2] = cube[idx][2][0];
		cube[idx][2][0] = tmp;
	}
}

void upRotate(char dir) {
	if (dir == '+') {
		tmp = cube[2][0][0];
		cube[2][0][0] = cube[5][0][0];
		cube[5][0][0] = cube[3][0][0];
		cube[3][0][0] = cube[4][0][0];
		cube[4][0][0] = tmp;

		tmp = cube[2][0][1];
		cube[2][0][1] = cube[5][0][1];
		cube[5][0][1] = cube[3][0][1];
		cube[3][0][1] = cube[4][0][1];
		cube[4][0][1] = tmp;

		tmp = cube[2][0][2];
		cube[2][0][2] = cube[5][0][2];
		cube[5][0][2] = cube[3][0][2];
		cube[3][0][2] = cube[4][0][2];
		cube[4][0][2] = tmp;
	}
	else if (dir == '-') {
		tmp = cube[2][0][0];
		cube[2][0][0] = cube[4][0][0];
		cube[4][0][0] = cube[3][0][0];
		cube[3][0][0] = cube[5][0][0];
		cube[5][0][0] = tmp;

		tmp = cube[2][0][1];
		cube[2][0][1] = cube[4][0][1];
		cube[4][0][1] = cube[3][0][1];
		cube[3][0][1] = cube[5][0][1];
		cube[5][0][1] = tmp;

		tmp = cube[2][0][2];
		cube[2][0][2] = cube[4][0][2];
		cube[4][0][2] = cube[3][0][2];
		cube[3][0][2] = cube[5][0][2];
		cube[5][0][2] = tmp;
	}
	swap(0, dir);
}

void downRotate(char dir) {
	if (dir == '+') {
		tmp = cube[2][2][0];
		cube[2][2][0] = cube[4][2][0];
		cube[4][2][0] = cube[3][2][0];
		cube[3][2][0] = cube[5][2][0];
		cube[5][2][0] = tmp;

		tmp = cube[2][2][1];
		cube[2][2][1] = cube[4][2][1];
		cube[4][2][1] = cube[3][2][1];
		cube[3][2][1] = cube[5][2][1];
		cube[5][2][1] = tmp;

		tmp = cube[2][2][2];
		cube[2][2][2] = cube[4][2][2];
		cube[4][2][2] = cube[3][2][2];
		cube[3][2][2] = cube[5][2][2];
		cube[5][2][2] = tmp;
	}
	else if (dir == '-') {
		tmp = cube[2][2][0];
		cube[2][2][0] = cube[5][2][0];
		cube[5][2][0] = cube[3][2][0];
		cube[3][2][0] = cube[4][2][0];
		cube[4][2][0] = tmp;

		tmp = cube[2][2][1];
		cube[2][2][1] = cube[5][2][1];
		cube[5][2][1] = cube[3][2][1];
		cube[3][2][1] = cube[4][2][1];
		cube[4][2][1] = tmp;

		tmp = cube[2][2][2];
		cube[2][2][2] = cube[5][2][2];
		cube[5][2][2] = cube[3][2][2];
		cube[3][2][2] = cube[4][2][2];
		cube[4][2][2] = tmp;
	}
	swap(1, dir);
}


/*
위 789
오 147
아래 321
왼 963
*/


void frontRotate(char dir) {
	if (dir == '+') {
		tmp = cube[0][2][0];
		cube[0][2][0] = cube[4][2][2];
		cube[4][2][2] = cube[1][0][2];
		cube[1][0][2] = cube[5][0][0];
		cube[5][0][0] = tmp;

		tmp = cube[0][2][1];
		cube[0][2][1] = cube[4][1][2];
		cube[4][1][2] = cube[1][0][1];
		cube[1][0][1] = cube[5][1][0];
		cube[5][1][0] = tmp;

		tmp = cube[0][2][2];
		cube[0][2][2] = cube[4][0][2];
		cube[4][0][2] = cube[1][0][0];
		cube[1][0][0] = cube[5][2][0];
		cube[5][2][0] = tmp;
	}
	else if (dir == '-') {
		tmp = cube[0][2][0];
		cube[0][2][0] = cube[5][0][0];
		cube[5][0][0] = cube[1][0][2];
		cube[1][0][2] = cube[4][2][2];
		cube[4][2][2] = tmp;

		tmp = cube[0][2][1];
		cube[0][2][1] = cube[5][1][0];
		cube[5][1][0] = cube[1][0][1];
		cube[1][0][1] = cube[4][1][2];
		cube[4][1][2] = tmp;

		tmp = cube[0][2][2];
		cube[0][2][2] = cube[5][2][0];
		cube[5][2][0] = cube[1][0][0];
		cube[1][0][0] = cube[4][0][2];
		cube[4][0][2] = tmp;
	}
	swap(2, dir);
}



void backRotate(char dir) {
	if (dir == '+') {
		tmp = cube[0][0][0];
		cube[0][0][0] = cube[5][0][2];
		cube[5][0][2] = cube[1][2][2];
		cube[1][2][2] = cube[4][2][0];
		cube[4][2][0] = tmp;

		tmp = cube[0][0][1];
		cube[0][0][1] = cube[5][1][2];
		cube[5][1][2] = cube[1][2][1];
		cube[1][2][1] = cube[4][1][0];
		cube[4][1][0] = tmp;

		tmp = cube[0][0][2];
		cube[0][0][2] = cube[5][2][2];
		cube[5][2][2] = cube[1][2][0];
		cube[1][2][0] = cube[4][0][0];
		cube[4][0][0] = tmp;
	}
	else if (dir == '-') {
		tmp = cube[0][0][0];
		cube[0][0][0] = cube[4][2][0];
		cube[4][2][0] = cube[1][2][2];
		cube[1][2][2] = cube[5][0][2];
		cube[5][0][2] = tmp;

		tmp = cube[0][0][1];
		cube[0][0][1] = cube[4][1][0];
		cube[4][1][0] = cube[1][2][1];
		cube[1][2][1] = cube[5][1][2];
		cube[5][1][2] = tmp;

		tmp = cube[0][0][2];
		cube[0][0][2] = cube[4][0][0];
		cube[4][0][0] = cube[1][2][0];
		cube[1][2][0] = cube[5][2][2];
		cube[5][2][2] = tmp;
	}
	swap(3, dir);
}




void leftRotate(char dir) {
	if (dir == '+') {
		tmp = cube[0][0][0];
		cube[0][0][0] = cube[3][2][2];
		cube[3][2][2] = cube[1][0][0];
		cube[1][0][0] = cube[2][0][0];
		cube[2][0][0] = tmp;

		tmp = cube[0][1][0];
		cube[0][1][0] = cube[3][1][2];
		cube[3][1][2] = cube[1][1][0];
		cube[1][1][0] = cube[2][1][0];
		cube[2][1][0] = tmp;

		tmp = cube[0][2][0];
		cube[0][2][0] = cube[3][0][2];
		cube[3][0][2] = cube[1][2][0];
		cube[1][2][0] = cube[2][2][0];
		cube[2][2][0] = tmp;
	}
	else if (dir == '-') {
		tmp = cube[0][0][0];
		cube[0][0][0] = cube[2][0][0];
		cube[2][0][0] = cube[1][0][0];
		cube[1][0][0] = cube[3][2][2];
		cube[3][2][2] = tmp;

		tmp = cube[0][1][0];
		cube[0][1][0] = cube[2][1][0];
		cube[2][1][0] = cube[1][1][0];
		cube[1][1][0] = cube[3][1][2];
		cube[3][1][2] = tmp;

		tmp = cube[0][2][0];
		cube[0][2][0] = cube[2][2][0];
		cube[2][2][0] = cube[1][2][0];
		cube[1][2][0] = cube[3][0][2];
		cube[3][0][2] = tmp;
	}
	swap(4, dir);
}


/*
위 369
앞 369
아래 369
뒤 741
*/

// 0~5 위 아래 앞 뒤 왼 오

void rightRotate(char dir) {
	if (dir == '+') {
		tmp = cube[0][0][2];
		cube[0][0][2] = cube[2][0][2];
		cube[2][0][2] = cube[1][0][2];
		cube[1][0][2] = cube[3][2][0];
		cube[3][2][0] = tmp;

		tmp = cube[0][1][2];
		cube[0][1][2] = cube[2][1][2];
		cube[2][1][2] = cube[1][1][2];
		cube[1][1][2] = cube[3][1][0];
		cube[3][1][0] = tmp;

		tmp = cube[0][2][2];
		cube[0][2][2] = cube[2][2][2];
		cube[2][2][2] = cube[1][2][2];
		cube[1][2][2] = cube[3][0][0];
		cube[3][0][0] = tmp;
	}
	else if (dir == '-') {
		tmp = cube[0][0][2];
		cube[0][0][2] = cube[3][2][0];
		cube[3][2][0] = cube[1][0][2];
		cube[1][0][2] = cube[2][0][2];
		cube[2][0][2] = tmp;

		tmp = cube[0][1][2];
		cube[0][1][2] = cube[3][1][0];
		cube[3][1][0] = cube[1][1][2];
		cube[1][1][2] = cube[2][1][2];
		cube[2][1][2] = tmp;

		tmp = cube[0][2][2];
		cube[0][2][2] = cube[3][0][0];
		cube[3][0][0] = cube[1][2][2];
		cube[1][2][2] = cube[2][2][2];
		cube[2][2][2] = tmp;
	}
	swap(5, dir);
}

void rotate(char side, char dir) {
	if (side == 'U') upRotate(dir);
	else if (side == 'D') downRotate(dir);
	else if (side == 'F') frontRotate(dir);
	else if (side == 'B') backRotate(dir);
	else if (side == 'L') leftRotate(dir);
	else if (side == 'R') rightRotate(dir);
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while (t--) {
		init();

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			rotate(a, b);
		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << cube[0][i][j];
			}
			cout << '\n';
		}



	}

	return 0;
}