#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
int main()
{
	double max = 0, a, sum = 0;
	int n;
	cin >> n;
	cout.precision(2);
	cout << fixed;
	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		if (max < a)
		{
			max = a;
		}
		sum = sum + a;
	}
	cout << sum * 100 / n / max;
	system("pause >> null");
	return 0;
}

