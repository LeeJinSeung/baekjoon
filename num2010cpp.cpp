#include <iostream>
using namespace std;


int main() {
	int n;
	cin >> n;
	int a;
	int count = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		count = count + a;
	}
	cout << count - n + 1;
	system("pause >> null");
	return 0;
}
