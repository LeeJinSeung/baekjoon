#include <iostream>
using namespace std;


int main() {
	long long N;
	cin >> N;
	long long sum = 0;
	sum = sum + (N - 1)*N*(N + 1) / 2;
	cout << sum;
	system("pause >> null");
	return 0;
}
