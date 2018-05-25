#include<iostream>
using namespace std;

int main()
{
	int number[9] = { 0 };
	int max = 0, count = 0;

	for (int i = 0; i < 9; i++) {
		cin >> number[i];
		if (max < number[i]) {
			max = number[i];
			count = i + 1;

		}
	}

	cout << max << endl << count;
	system("pause >> null");
	return 0;
}