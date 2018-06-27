#include <iostream>
using namespace std;
int main()
{
	int arr[100000];
	int n, k, swap;
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < k; ++i)
	{
		for (int j = 0; j < n - i - 1; ++j) {
			if (arr[j] > arr[j + 1])
			{
				swap = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = swap;
			}
		}
	}

	for (int h = 0; h < n; ++h)
	{
		printf("%d ", arr[h]);
	}

	//system("pause >> null");
	return 0;
}
