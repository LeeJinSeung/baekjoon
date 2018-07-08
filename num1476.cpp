#include <iostream>

using namespace std;

int main() {
	int e, s, m, result;
	cin >> e >> s >> m;
	result = ((e * 13 * 28 * 19) + (s * 17 * 15 * 19) + (m * 10 * 15 * 28)) % (15 * 28 * 19);
	if (result == 0) {
		cout << 15 * 28 * 19;
	}
	else {
		cout << result;
	}
	system("pause >> null");
	return 0;
}
