#include <iostream>
using namespace std;

int main()
{
	int ave = 0;
	int score;
	for (int i = 0; i < 5; ++i) {
		cin >> score;
		if (score < 40) {
			score = 40;
		}
		ave = ave + score;
	}
	cout << ave / 5;

	system("pause >> null");
	return 0;
}

