#include <iostream>

using namespace std;

int main() {
	int a, b, count, min = 0, max = 0;
	cin >> a >> b;
	int arr1[7] = { 0 }, arr2[7] = { 0 };
	for (int i = 0; i < 7; ++i) {
		arr1[i] = a % 10 + b % 10;
		if (a % 10 == 5) {
			arr1[i]++;
		}

		if (b % 10 == 5) {
			arr1[i]++;
		}

		arr2[i] = a % 10 + b % 10;

		if (a % 10 == 6) {
			arr2[i]--;
		}

		if (b % 10 == 6) {
			arr2[i]--;
		}


		a = a / 10;
		b = b / 10;
		if (a == 0 && b == 0) {
			break;
		}
	}
	for (int i = 6; i >= 0; --i) {
		min = min * 10 + arr2[i];
	}
	for (int i = 6; i >= 0; --i) {
		max = max * 10 + arr1[i];
	}
	cout << min << " " << max;

	system("pause >> null");
	return 0;
}
