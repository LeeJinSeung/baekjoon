#include <iostream>
#include <cmath>
using namespace std;

int x[50000];
int y[50000];

int main() {
	int n;
	int max = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (max < abs(x[i] - x[j]) + abs(y[i] - y[j])) {
				max = abs(x[i] - x[j]) + abs(y[i] - y[j]);
			}
		}
	}
	cout << max;
	system("pause >> null");
	return 0;
}
