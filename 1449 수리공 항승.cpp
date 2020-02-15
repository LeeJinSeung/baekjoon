#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <cmath>
#include <stack>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, l;
int arr[1000];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> l;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	int tmp = arr[0];
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		if (tmp + l - 1 < arr[i]) {
			tmp = arr[i];
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}