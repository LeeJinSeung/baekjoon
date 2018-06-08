#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	int n, a, x;
	cin >> n >> x;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		;		if (a < x)
		{
			printf("%d ", a);
		}
	}
	system("pause >> null");
	return 0;
}