#include <iostream>
#include <cmath>
using namespace std;


int main() {
	int N;
	int tsq = 1;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		tsq = tsq * 2;
	}
	cout << (tsq + 1)*(tsq + 1);
	system("pause >> null");
	return 0;
}
