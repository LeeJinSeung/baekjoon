#include <iostream>

using namespace std;

int main()
{
	int n;
	int fac = 1;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		fac = fac * i;
	}
	cout << fac;
	system("pause >> null");
	return 0;
}

