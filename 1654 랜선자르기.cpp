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

int k, n;
int arr[10000];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> k >> n;

	for (int i = 0; i < k; i++) cin >> arr[i];

	sort(arr, arr + k);

	ll l = 1;
	ll r = arr[k - 1];

	while (l <= r) {
		ll mid = (l + r) / 2;
		int cnt = 0;


		for (int i = 0; i < k; i++) {
			cnt += (arr[i] / mid);
		}

		// cout << l << " " << r << " " << mid << " " << " " << cnt << endl;

		if (cnt >= n) {
			l = mid + 1;
		}
		else r = mid - 1;
	}

	cout << r;


	return 0;
}