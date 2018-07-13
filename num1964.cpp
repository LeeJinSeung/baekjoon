#include <iostream>
using namespace std;


int main() {
	cin.tie(NULL);
	int N;
	cin >> N;
	int result = 5;
	for (int i = 2; i <= N; ++i) {
		result = result % 45678 + 3 * i % 45678 + 1;
	}
	cout << result % 45678;
	system("pause >> null");
	return 0;
}
