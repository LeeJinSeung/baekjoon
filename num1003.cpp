#include <iostream>
#include <string>
using namespace std;

int main() {
	int tc, num;
	cin >> tc;
	int *z = new int[tc];
	int *o = new int[tc];
	for (int i = 0; i < tc; ++i) {
		int num;
		cin >> num;
		int arr[2][40] = { 0 };
		arr[0][0] = 1;
		arr[1][1] = 1;
		for (int j = 2; j <= num; ++j) {
			arr[0][j] = arr[0][j - 2] + arr[0][j - 1];
			arr[1][j] = arr[1][j - 2] + arr[1][j - 1];
		}
		z[i] = arr[0][num];
		o[i] = arr[1][num];
	}
	for (int i = 0; i < tc; ++i) {
		cout << z[i] << " " << o[i] << endl;
	}
	delete[]z;
	delete[]o;

	system("pause >> null");
	return 0;
}
