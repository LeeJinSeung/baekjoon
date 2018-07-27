#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

char dp[1000001];

int main() {
	int t;
	cin >> t;
	for (int i = 0; i <= t; ++i) {
		scanf("%1c", &dp[i]);
	}

	for (int i = t; i > 1; --i) {
		if (dp[i] + dp[i - 1] == 'A' + 'C' || dp[i] + dp[i - 1] == 'G' + 'T') {
			dp[i - 1] = 'A';
		}
		else if (dp[i] + dp[i - 1] == 'A' + 'T' || dp[i] + dp[i - 1] == 'C' + 'T') {
			dp[i - 1] = 'G';
		}
		else if (dp[i] + dp[i - 1] == 'A' + 'G') {
			dp[i - 1] = 'C';
		}
		else if (dp[i] + dp[i - 1] == 'C' + 'G') {
			dp[i - 1] = 'T';
		}
	}
	cout << dp[1];

	system("pause >> null");
	return 0;
}
