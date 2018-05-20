#include <iostream>
#include <string>
using namespace std;

long long int gcd(long long int num1, long long int num2) {
	long long int r = 0;
	while (num2)
	{
		r = num1 % num2;
		num1 = num2;
		num2 = r;
	}
	return num1;
}

int main()
{
	long long int num1, num2;
	long long int result;
	string st = "";
	cin >> num1 >> num2;
	result = gcd(num1, num2);
	if (result > 10000000) {
		result = result % 10000000;
	}
	while (result) {
		cout << '1';
		result--;
	}
	cout << '\n';

	system("pause >> null");
	return 0;
}

