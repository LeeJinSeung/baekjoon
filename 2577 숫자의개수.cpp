#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	cin.tie(NULL);
	int a, b, c, m;
	int arr[10] = { 0 };
	cin >> a >> b >> c;
	m = a * b * c;
	while (m > 10)
	{
		arr[m % 10] = arr[m % 10] + 1;
		m = m / 10;
	}
	arr[m] = arr[m] + 1;
	for (int i = 0; i < 10; ++i)
	{
		cout << arr[i] << endl;
	}

	system("pause >> null");
	return 0;
}