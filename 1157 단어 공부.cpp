#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int count[26] = { 0 };
	int max[2] = { 0 };
	int pos;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] < 'A' || str[i] > 'z') {
			cout << "�߸� �Է� �ϼ̽��ϴ�.";
		}
		else if (str[i] <= 'Z') {
			count[str[i] - 'A'] += 1;
		}
		else if (str[i] >= 'a') {
			count[str[i] - 'a'] += 1;
		}
		else {
			cout << "�߸� �Է� �ϼ̽��ϴ�.";
		}
	}
	for (int i = 0; i < 26; ++i) {
		if (max[0] <= count[i] && max[1] <= count[i]) {
			if (max[0] <= max[1]) {
				max[0] = count[i];
			}
			else {
				max[1] = count[i];
			}
			pos = i;
		}
	}
	if (max[0] == max[1]) {
		cout << "?";
	}
	else {
		cout << (char)(pos + 'A');
	}
	system("pause >> null");
	return 0;
}

