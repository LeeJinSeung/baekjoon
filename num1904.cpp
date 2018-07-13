#include <iostream>
using namespace std;


int main() {
	cin.tie(NULL);
	int n;
	cin >> n;
	int arr[2] = { 1,1 };
	for (int i = 0; i < n; ++i) {
		if (i % 2 == 0) {
			arr[0] = (arr[0] % 15746 + arr[1] % 15746) % 15746;
		}
		else {
			arr[1] = (arr[0] % 15746 + arr[1] % 15746) % 15746;
		}
	}
	if (n % 2 == 0) {
		cout << arr[0] % 15746;
	}
	else {
		cout << arr[1] % 15746;
	}
	system("pause >> null");
	return 0;
}
