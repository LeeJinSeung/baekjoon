#include <iostream>

using namespace std;

int main()
{
	int arr[4];
	int sum = 0;
	int max = 0;
	int count;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 4; ++j) {
			cin >> arr[j];
			sum += arr[j];
		}
		if (max < sum) {
			max = sum;
			count = i;
		}
		sum = 0;

	}
	cout << count + 1 << " " << max;
	system("pause >> null");
	return 0;
}

