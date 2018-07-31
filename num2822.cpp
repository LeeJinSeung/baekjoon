#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int score[8];
int num[8];
vector<int> v;

int main() {
	int sum = 0;
	for (int i = 0; i < 8; ++i) {
		cin >> num[i];
		score[i] = num[i];
	}
	sort(score, score + 8);

	for (int i = 3; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (score[i] == num[j]) {
				v.push_back(j + 1);
			}
		}
		sum += score[i];
	}
	cout << sum << "\n";
	sort(v.begin(), v.end());
	for (int i = 0; i < 5; ++i) {
		cout << v[i] << " ";
	}
	system("pause >> null");
	return 0;
}
