#include <iostream>
#include <string>
using namespace std;




int main() {
	int tc;
	int result = 0;
	cin >> tc;
	int *a = new int[tc];
	int *b = new int[tc];
	for (int i = 0; i < tc; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < tc; ++i) {
		cin >> b[i];
	}
	for (int i = 0; i < tc; ++i) {
		int min = 100, max = -1;
		for (int j = 0; j <tc; ++j) {
			if (min > a[j]) {
				int temp = min;
				min = a[j];
				a[j] = temp;
			}
			if (max < b[j]) {
				int temp = max;
				max = b[j];
				b[j] = temp;
			}
		}
		result += min * max;
	}
	cout << result;
	delete[]a;
	delete[]b;

	system("pause >> null");
	return 0;
}
