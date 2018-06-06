#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int num1 = 1, num2 = 0;
	for (int i = 0; i < n; ++i) {
		if (i % 2 == 1)
		{
			num1 += num2;
		}
		else {
			num2 += num1;
		}
	}
	if (n % 2 == 1) {
		cout << num1;
	}
	else {
		cout << num2;
	}

	system("pause >> null");
	return 0;
}
