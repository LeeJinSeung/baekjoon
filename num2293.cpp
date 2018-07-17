#include <iostream>
#include <algorithm>
using namespace std;

int arr[10001];
int coin[100];

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> coin[i];
	}
	arr[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j <= k; ++j) {
			arr[j] += arr[j - coin[i]];
		}
	}
	cout << arr[k];

	system("pause >> null");
	return 0;
}
