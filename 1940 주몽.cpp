#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 15001;

int n, cnt, x;
int arr[MAX];

int binarySearch(int l, int r, int tar) {
	int mid = (l + r) / 2;
	while (l < r) {
		mid = (l + r) / 2;
		if (arr[mid] < tar) l = mid + 1;
		else if (arr[mid] > tar) r = mid - 1;
		else return 1;
	}
	if (arr[l] == tar) return 1;
	return 0;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> x;
	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		cnt += binarySearch(0, n - 1, x - arr[i]);
	}
	cout << cnt / 2;

	return 0;
}