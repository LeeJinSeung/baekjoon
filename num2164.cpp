#include <iostream>
using namespace std;

int main() {
	int N;
	int tsq = 1;
	cin >> N;
	while (2 * tsq < N) {
		tsq *= 2;
	}
	if (N%tsq == 0) {
		cout << N;
	}
	else {
		cout << (N%tsq) * 2;
	}
	system("pause >> null");
	return 0;
}
