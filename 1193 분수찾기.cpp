#include <iostream>
using namespace std;
int main()
{
	int n;
	int count = 2;
	cin >> n;
	int dec = 1;
	while (n > dec)
	{
		n = n - dec;
		++dec;
		++count;
	}
	if (count % 2 == 1) {
		cout << n << "/" << (count - n);
	}
	else {
		cout << (count - n) << "/" << n;
	}
	system("pause >> null");
	return 0;
}

