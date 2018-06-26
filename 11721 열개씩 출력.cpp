#include<iostream>
#include<string>
using namespace std;

int main()
{
	string c;
	cin >> c;
	for (int i = 0; i < c.size(); i += 10)
	{
		cout << c.substr(i, 10) << endl;
	}

	system("pause >> null");
	return 0;
}