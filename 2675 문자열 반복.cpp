#include <iostream>
using namespace std;

int main()
{
	int tc;
	int r;
	char s[21];
	char t[1000][161];
	cin >> tc;
	for (int i = 0; i < tc; ++i) {
		cin >> r >> s;
		for (int j = 0; j < 20; ++j) {
			if (s[j] == '\0') {
				t[i][j*r] = '\0';
				break;
			}
			for (int k = j * r; k < r*(j + 1); ++k) {
				t[i][k] = s[j];
			}
		}
	}
	for (int i = 0; i < tc; ++i) {
		cout << t[i] << endl;
	}

	system("pause >> null");
	return 0;
}

