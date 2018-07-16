#include <iostream>

using namespace std;

int main() {
	int n;
	long long num1 = 0, num2 = 1;
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		if (i % 2 == 0) {
			num1 = num1 + num2;
		}
		else {
			num2 = num1 + num2;
		}
	}
	if (n % 2 == 0) {
		cout << num1;
	}
	else {
		cout << num2;
	}
	system("pause >> null");
	return 0;
}
