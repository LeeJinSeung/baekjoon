#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	if (x > w - x) {
		x = w - x;
	}

	if (y > h - y) {
		y = h - y;
	}

	if (x > y) {
		cout << y;
	}
	else {
		cout << x;
	}
	system("pause >> null");
	return 0;
}
