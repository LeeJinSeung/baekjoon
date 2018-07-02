#include <iostream>
#include <string>
using namespace std;

int comb(int num1, int num2, int res1)
{
	int lnum = num1;
	int rnum = num2;
	for (int i = 1; i <= num2 - num1; i++) {
		res1 = res1 * rnum / i;
		rnum--;
	}
	return res1;
}


int main() {
	int tc;
	cin >> tc;
	int *a = new int[tc];
	for (int i = 0; i < tc; ++i) {
		int left, right;
		cin >> left >> right;
		if (2 * left > right) {
			left = right - left;
		}
		int result = 1;
		result = comb(left, right, result);
		a[i] = result;

	}

	for (int i = 0; i < tc; ++i) {
		cout << a[i] << endl;
	}
	delete[]a;
	system("pause >> null");
	return 0;
}
