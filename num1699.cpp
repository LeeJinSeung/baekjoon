#include <iostream>
#include <cmath>
using namespace std;

int arr[100001];

// 모든 정수는 4개의 제곱의 합으로 표현이 가능하다.
// 즉 이값의 최대는 4이며 최소는 1이므로 arr[N]을 4로
// 초기화시켜서 더 적은 갯수의 제곱의 합으로 표현 가능할 때 
// arr[N]의 값을 바꿔나간다.

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