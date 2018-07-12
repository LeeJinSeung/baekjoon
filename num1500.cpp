#include <iostream>
using namespace std;

int arr[100];

int main() {
	int S, K;
	int pos = 0;
	long long max_Mul = 1;
	cin >> S >> K;
	int div = S / K;
	int rem = S - (div*K);
	for (int i = 0; i < K; ++i) {
		arr[i] = div;
		if (rem != 0) {
			arr[i]++;
			rem--;
		}
		max_Mul *= arr[i];
	}
	cout << max_Mul;
	system("pause >> null");
	return 0;
}
