#include <iostream>
using namespace std;


int main() {
	cin.tie(NULL);
	double arr[2][2];
	int count = 0;
	int mcount = 0;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			cin >> arr[i][j];
		}
	}
	double max = (arr[0][0] / arr[1][0]) + (arr[0][1] / arr[1][1]);
	while (count<4) {
		double swap = arr[0][0];
		arr[0][0] = arr[1][0];
		arr[1][0] = arr[1][1];
		arr[1][1] = arr[0][1];
		arr[0][1] = swap;
		count++;
		if (max < (arr[0][0] / arr[1][0]) + (arr[0][1] / arr[1][1])) {
			max = (arr[0][0] / arr[1][0]) + (arr[0][1] / arr[1][1]);
			mcount = count;
		}


	}
	cout << mcount;
	system("pause >> null");
	return 0;
}
