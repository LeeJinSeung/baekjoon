#include <iostream>
using namespace std;

int dvSize = 1000000000;
int dp[400][400];

int comb(int n, int k) {
	int &ret = dp[n][k];
	if (ret != 0) return ret;
	if (k == 0 || k == n) return 1;

	ret = comb(n - 1, k - 1) % dvSize + comb(n - 1, k) % dvSize;
	return ret;
}

int main() {
	cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	int min = N;
	if (min > K - 1) {
		min = K - 1;
	}
	cout << comb(N + K - 1, min) % dvSize;
	system("pause >> null");
	return 0;
}
