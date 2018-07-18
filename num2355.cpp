#include <iostream>
using namespace std;


int main() {
	long long A, B;
	cin >> A >> B;
	if (A > B) {
		long long swap;
		swap = B;
		B = A;
		A = swap;
	}
	if ((B * (B + 1) / 2 - A * (A - 1) / 2) >= 2147483647)
	{
		cout << 2147483647;
	}
	else if ((B * (B + 1) / 2 - A * (A - 1) / 2) <= -2147483648) {
		cout << -2147483648;
	}
	else {
		cout << (B * (B + 1) / 2 - A * (A - 1) / 2);
	}
	system("pause >> null");
	return 0;
}
