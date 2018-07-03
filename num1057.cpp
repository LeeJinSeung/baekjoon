#include <iostream>
using namespace std;


int main() {
	int n, kim, lim;
	cin >> n >> kim >> lim;
	int round = 1;
	while (n > 0) {
		if (kim + 1 == lim && lim % 2 == 0) {
			break;
		}
		else if (lim + 1 == kim && kim % 2 == 0) {
			break;
		}
		if (kim % 2 == 1) {
			kim = (kim + 1) / 2;
		}
		else {
			kim = kim / 2;
		}

		if (lim % 2 == 1) {
			lim = (lim + 1) / 2;
		}
		else {
			lim = lim / 2;
		}
		round++;
	}
	cout << round;
	system("pause >> null");
	return 0;
}
