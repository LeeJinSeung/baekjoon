#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

char dp[1000001];

char dna(int n) {
	char &ret = dp[n];
	if (n == 1) return ret;

	if (dp[n] + dp[n - 1] == 'A' + 'C' || dp[n] + dp[n - 1] == 'G' + 'T') {
		dp[n] = 0;
		dp[n - 1] = 'A';
	}
	else if (dp[n] + dp[n - 1] == 'A' + 'T' || dp[n] + dp[n - 1] == 'C' + 'T') {
		dp[n] = 0;
		dp[n - 1] = 'G';
	}
	else if (dp[n] + dp[n - 1] == 'A' + 'G') {
		dp[n] = 0;
		dp[n - 1] = 'C';
	}
	else if (dp[n] + dp[n - 1] == 'C' + 'G') {
		dp[n] = 0;
		dp[n - 1] = 'T';
	}
	else {
		dp[n] = 0;
	}
	return dna(n - 1);
}


int main() {
	int t;
	cin >> t;
	for (int i = 0; i <= t; ++i) {
		scanf("%1c", &dp[i]);
	}
	cout << dna(t);

	system("pause >> null");
	return 0;
}
