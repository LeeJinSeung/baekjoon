#include <iostream>
#include <string>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	long long arr[2] = { 0,1 };
	for (int i = 2; i <= tc; ++i) {
		if (i % 2 == 0) {
			arr[0] += arr[1];
		}
		else {
			arr[1] += arr[0];
		}
	}
	if (tc >= 0 && tc % 2 == 0) {
		cout << arr[0];
	}
	else if (tc >= 0 && tc % 2 == 1) {
		cout << arr[1];
	}

	system("pause >> null");
	return 0;
}
