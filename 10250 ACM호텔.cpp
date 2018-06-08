#include <iostream>
using namespace std;

int main()
{
	int tc;
	cin >> tc;
	int *a = new int[tc];
	for (int i = 0; i < tc; ++i) {
		int hei, wid, cus;
		cin >> hei >> wid >> cus;
		if (cus % hei != 0) {
			a[i] = (cus % hei) * 100 + (cus / hei) + 1;
		}
		else {
			a[i] = hei * 100 + (cus / hei);
		}
	}

	for (int i = 0; i < tc; ++i) {
		cout << a[i] << endl;
	}
	delete[] a;

	system("pause >> null");
	return 0;
}

