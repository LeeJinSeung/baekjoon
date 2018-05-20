#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	int m = 13, d = 0;
	int arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	while (m > 12) {
		cin >> m >> d;
	}
	for (int i = 1; i <m; ++i)
	{
		d = d + arr[i - 1];
	}
	d = d % 7;
	switch (d) {
	case 0:
		cout << "SUN";
		break;
	case 1:
		cout << "MON";
		break;
	case 2:
		cout << "TUE";
		break;
	case 3:
		cout << "WED";
		break;
	case 4:
		cout << "THU";
		break;
	case 5:
		cout << "FRI";
		break;
	case 6:
		cout << "SAT";
		break;
	default:
		break;
	}
	system("pause >> null");
	return 0;
}

