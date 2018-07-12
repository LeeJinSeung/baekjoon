#include <iostream>
using namespace std;

int main() {
	int A, B, C;
	int sale;
	cin >> A >> B >> C;
	if (B >= C) {
		cout << -1;
		system("pause >> null");
		return 0;
	}
	else {
		sale = A / (C - B) + 1;
		cout << sale;
	}
	system("pause >> null");
	return 0;
}
