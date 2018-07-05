#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, f, a;
	cin >> n >> f;
	a = n - (n%f);
	if (n % 100 != a % 100) {
		a = a + f;
	}
	while (n / 100 == (a - f) / 100) {
		a = a - f;
	}
	a = a % 100;
	if (a < 10) {
		cout << 0 << a;
	}
	else {
		cout << a;
	}
	system("pause >> null");
	return 0;
}
