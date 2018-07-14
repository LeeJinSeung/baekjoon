#include <iostream>
using namespace std;


int main() {
	int n;
	cin >> n;
	int arr[100];
	int count = 0;
	int c = 0;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		for (int j = 1; j <= arr[i]; ++j) {
			if (arr[i] % j == 0) {
				c++;
			}
		}
		if (c == 2) {
			count++;
		}
		c = 0;
	}
	cout << count;
	system("pause >> null");
	return 0;
}
