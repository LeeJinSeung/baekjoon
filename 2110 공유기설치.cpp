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
#include <functional>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, c, res;
int arr[200001];


int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	int l = 1;
	int r = arr[n - 1] - arr[0];

	while (l <= r) {
		int mid = (l + r) / 2;
		int cnt = 1;
		int start = arr[0];

		for (int i = 1; i < n; i++) {
			if (arr[i] - start >= mid) {
				cnt++;
				start = arr[i];
			}
		}

		if (cnt >= c) {
			res = mid;
			l = mid + 1;
		}
		else r = mid - 1;

	}
	cout << res;


	return 0;
}