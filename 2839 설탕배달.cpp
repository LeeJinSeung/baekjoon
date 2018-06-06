#include <iostream>
using namespace std;

int main()
{
	int n, min = 10000;
	cin >> n;
	if (n>2)
	{
		for (int i = 0; i <= n / 3; i++)
		{
			if (n == 3 * i)
			{
				if (min > i)
				{
					min = i;
				}
			}
			for (int j = 0; j <= n / 5; j++)
			{
				if (n == 5 * j)
				{
					if (min > j)
					{
						min = j;
					}
				}
				if (n == 5 * j + 3 * i)
				{
					if (min > i + j)
					{
						min = i + j;
					}
				}
			}
		}
		if (min == 10000)
		{
			min = -1;
		}
	}
	else
	{
		min = -1;
	}
	cout << min << endl;
	system("pause >> null");
	return 0;
}