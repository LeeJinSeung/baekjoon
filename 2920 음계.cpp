#include <iostream>
using namespace std;

int main()
{
	int Iarr[8];
	int count = 0;
	for (int i = 0; i < 8; ++i) {
		cin >> Iarr[i];
	}
	for (int i = 0; i < 7; ++i) {
		if (Iarr[i] < Iarr[i + 1]) {
			++count;
		}
	}
	if (count == 7) {
		cout << "ascending";
	}
	else if (count == 0) {
		cout << "descending";
	}
	else {
		cout << "mixed";
	}


	system("pause >> null");
	return 0;
}

