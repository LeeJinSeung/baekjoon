#include <iostream>
#include <algorithm>
using namespace std;

int straw[1000000];

int main() {
	int N;
	int sum = -1;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> straw[i];
	}
	sort(straw, straw + N);
	for (int i = N - 1; i > 1; --i) {
		if (straw[i] < straw[i - 1] + straw[i - 2]) {
			sum = straw[i] + straw[i - 1] + straw[i - 2];
			break;
		}
	}
	cout << sum;
	return 0;
}