#include <iostream>
using namespace std;

int arr[100000];
int main() {
	int N;
	int room;
	cin >> N;
	for (int i = 1; i < 100000; ++i) {
		arr[i] = 3 * i*(i - 1) + 1;
		if (arr[i] >= N) {
			room = i;
			break;
		}
	}
	cout << room;
	system("pause >> null");
	return 0;
}
