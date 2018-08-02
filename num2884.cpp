#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int h, m;
	cin >> h >> m;
	if (h != 0) {
		if (m >= 45) {
			cout << h << " " << m - 45;
		}
		else {
			cout << h - 1 << " " << m + 15;
		}
	}
	else {
		if (m >= 45) {
			cout << h << " " << m - 45;
		}
		else {
			cout << 23 << " " << m + 15;
		}
	}
	system("pause >> null");
	return 0;
}
