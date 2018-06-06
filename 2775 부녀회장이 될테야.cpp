#include <iostream>

using namespace std;

int main()
{
	int tc;
	int k, n;
	cin >> tc;
	int *a = new int[tc];
	for (int i = 0; i < tc; ++i) {
		cin >> k >> n;
		int arr[15][15] = { 0 };
		for (int j = 0; j < k + 1; ++j) {
			for (int q = 0; q < n + 1; ++q) {
				for (int p = 0; p <= q; ++p) {
					if (j > 0) {
						arr[j][q] = arr[j - 1][p] + arr[j][q];
					}
					else {
						arr[j][q] = arr[j][q] + 1;
					}
				}

			}
		}
		a[i] = arr[k][n - 1];

	}
	for (int i = 0; i < tc; ++i) {
		cout << a[i] << endl;
	}
	delete[]a;
	system("pause >> null");
	return 0;
}

