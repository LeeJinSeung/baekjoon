#include <iostream>
#include <cstring>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int arr[100001]; \

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		if (arr[i - 1] >= 0) {
			arr[i] += arr[i - 1];
		}
	}
	sort(arr + 1, arr + n + 1);
	cout << arr[n];

	return 0;
}