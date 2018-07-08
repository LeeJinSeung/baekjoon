#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int num, a;
	int max = 0;
	cin >> num;
	double arr[9] = { 0 };
	while (num > 9) {
		a = num % 10;
		num = num / 10;
		if (a == 9) {
			a = 6;
		}
		arr[a]++;
	}
	if (num == 9) {
		num = 6;
	}
	arr[num]++;
	arr[6] = ceil((arr[6] / 2));
	for (int i = 0; i < 9; ++i) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	cout << max;
	system("pause >> null");
	return 0;
}
