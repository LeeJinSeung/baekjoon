#include <iostream>
using namespace std;


int main() {
	int N;
	int min = 5000;
	cin >> N;
	for (int i = 0; i <= 1334; ++i) {
		for (int j = 0; j <= 1000; ++j) {
			if (3 * i + 5 * j == N) {
				if (min > i + j) {
					min = i + j;
				}
			}
			else if (3 * i + 5 * j >= N) {
				break;
			}
		}
		if (3 * i > N) {
			break;
		}
	}
	if (min != 5000) cout << min;
	else cout << -1;
	system("pause >> null");
	return 0;
}


