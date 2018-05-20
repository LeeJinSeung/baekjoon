#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int sum = 0, m, n, min = 10000, swap;
	cin >> m >> n;
	if (m > n) {
		swap = m;
		n = m;
		n = swap;
	}
	for (int i = n; i >= m; --i)
	{
		for (int j = 1; j <= 100; ++j)
		{
			if (i >= j * j)
			{
				if (i == j * j) {
					sum = sum + i;
					min = i;
				}
			}
			else
			{
				break;
			}
		}
	}
	if (sum == 0)
	{
		sum = -1;
		cout << sum;
	}
	else {
		cout << sum << endl << min;
	}

	system("pause >> null");
	return 0;
}