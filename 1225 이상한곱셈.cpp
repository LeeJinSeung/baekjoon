#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	long long int ca = 0, cb = 0;
	for (int i = 0; i < a.size(); ++i) {
		ca = ca + a[i] - '0';
	}
	for (int i = 0; i < b.size(); ++i) {
		cb = cb + b[i] - '0';
	}
	cout << ca * cb;
	system("pause >> null");
	return 0;
}
