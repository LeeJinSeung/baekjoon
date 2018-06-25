#include <iostream>

using namespace std;

int comb(int num1, int num2, int res1)
{
	if (num1 == num2) {
		return res1;
	}
	else {
		res1 = res1 * num1;
		--num1;
		return comb(num1, num2, res1);
	}
}

int fact(int n, int res2)
{
	if (n == 0) {
		return res2;
	}
	else {
		res2 = res2 * n;
		--n;
		return fact(n, res2);
	}
}

int main()
{
	int k, n;
	int res1 = 1, res2 = 1;
	cin >> k >> n;
	int cresult;
	cresult = comb(k, n, res1);
	int fresult;
	fresult = fact(k - n, res2);
	cout << cresult / fresult;
	system("pause >> null");
	return 0;
}

