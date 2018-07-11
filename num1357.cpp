#include <iostream>
using namespace std;

int arr[4];

int rev(int n) {
	int num = n;
	n = 0;
	int pos = 0;
	while (num > 0) {
		arr[pos] = num % 10;
		n = n * 10 + arr[pos];
		pos++;
		num = num / 10;
	}
	return n;
}

int main() {
	int X, Y;
	cin >> X >> Y;
	int result = rev(rev(X) + rev(Y));
	cout << result;
	system("pause >> null");
	return 0;
}
