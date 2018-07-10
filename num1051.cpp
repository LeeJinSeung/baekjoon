#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int square[100][100];

int main() {
	int N, M, min;
	int sqsize = 1;
	cin >> N >> M;
	if (N >= M) {
		min = M;
	}
	else {
		min = N;
	}
	memset(square, -1, sizeof(square));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			scanf("%1d", &square[i][j]);
		}
	}
	for (int i = 0; i < N - 1; ++i) {
		for (int j = 0; j < M - 1; ++j) {
			for (int k = 1; k < min; ++k) {
				if (square[i][j] == square[i + k][j] && square[i][j + k] == square[i + k][j + k] && square[i + k][j] == square[i][j + k]) {
					if (sqsize < (k + 1) * (k + 1))
						sqsize = (k + 1) * (k + 1);
				}
			}
		}
	}
	cout << sqsize;
	system("pause >> null");
	return 0;
}
