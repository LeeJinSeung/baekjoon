#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int N;
	int arr[55];

	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}

	if (N == 1) {
		cout << "A";
		system("pause >> null");
		return 0;
	}
	else if (N == 2) {
		if (arr[0] == arr[1]) {
			cout << arr[0];
			system("pause >> null");
			return 0;
		}
		cout << "A";
		system("pause >> null");
		return 0;
	}

	int q;
	if (arr[1] == arr[0]) {
		q = 0;
	}
	else {
		q = (arr[2] - arr[1]) / (arr[1] - arr[0]);
	}
	int r = arr[1] - (arr[0] * q);


	for (int i = 1; i < N; ++i) {
		if (arr[i] != (arr[i - 1] * q + r)) {
			cout << "B";
			system("pause >> null");
			return 0;
		}
	}

	cout << arr[N - 1] * q + r;

	system("pause >> null");
	return 0;
}
