#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
int main()
{
	int arr[3][4];
	int sum[3] = { 0,0,0 }, count = 0;
	for (int i = 0; i < 3; ++i) {
		while (count < 4)
		{
			cin >> arr[count][i];
			if (arr[i][count] == 0 || arr[i][count] == 1)
			{
				sum[i] = sum[i] + arr[i][count];
				count++;
			}
		}
		count = 0;
	}
	for (int j = 0; j < 3; ++j) {
		switch (sum[j])
		{
		case 0: cout << 'D' << endl;
			break;
		case 1: cout << 'C' << endl;
			break;
		case 2: cout << 'B' << endl;
			break;
		case 3: cout << 'A' << endl;
			break;
		case 4: cout << 'E' << endl;
			break;
		default:
			break;
		}
	}
	system("pause >> null");
	return 0;
}

