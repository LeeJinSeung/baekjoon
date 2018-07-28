#include <iostream>
#include <cmath>
using namespace std;

int arr[100001];

// ��� ������ 4���� ������ ������ ǥ���� �����ϴ�.
// �� �̰��� �ִ�� 4�̸� �ּҴ� 1�̹Ƿ� arr[N]�� 4��
// �ʱ�ȭ���Ѽ� �� ���� ������ ������ ������ ǥ�� ������ �� 
// arr[N]�� ���� �ٲ㳪����.

int main() {
	int N;
	cin >> N;
	arr[N] = 4;
	for (int i = 1; i <= ceil(sqrt(N)); ++i) {
		if (i *i == N) {
			if (arr[N]>1) arr[N] = 1;
			break;
		}
		for (int j = 1; j <= ceil(sqrt(N / 2)); ++j) {
			if (i *i + j * j == N) {
				if (arr[N]>2) arr[N] = 2;
				break;
			}
			for (int k = 1; k <= ceil(sqrt(N / 3)); ++k) {
				if (i *i + j * j + k * k == N) {
					if (arr[N]>3) arr[N] = 3;
					break;
				}
			}
		}
	}
	cout << arr[N];
	system("pause >> null");
	return 0;
}