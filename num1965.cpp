#include <iostream>
using namespace std;

int arr[1001];
int box[1001];

int main() {
	int n;
	int max;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}
	box[1] = 1;
	max = box[1];
	for (int i = 2; i <= n; ++i) {
		box[i] = 1;
		for (int j = 1; j < i; ++j) {
			if (arr[j] < arr[i]) {
				if (box[i] < box[j] + 1) {
					box[i] = box[j] + 1;
				}
			}
		}
		if (max < box[i]) {
			max = box[i];
		}
	}
	cout << max;
	system("pause >> null");
	return 0;
}
