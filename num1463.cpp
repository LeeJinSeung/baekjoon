#include <iostream>
using namespace std;

int arr[1000001];

int main() {
	int X;
	cin >> X;
	for (int i = 2; i <= X; ++i) {
		arr[i] = arr[i - 1] + 1;
		if (i % 2 == 0) {
			if (arr[i / 2] + 1 < arr[i]) {
				arr[i] = arr[i / 2] + 1;
			}
		}

		if (i % 3 == 0) {
			if (arr[i / 3] + 1 < arr[i]) {
				arr[i] = arr[i / 3] + 1;
			}
		}
	}
	cout << arr[X];
	system("pause >> null");
	return 0;
}
