#include <iostream>
using namespace std;


int main() {
	int x;
	int count = 0;
	cin >> x;
	while (x != 0) {
		if (x % 2 == 1) {
			count++;
		}
		x = x / 2;
	}
	cout << count;
	system("pause >> null");
	return 0;
}
