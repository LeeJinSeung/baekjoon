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

int n, m;
int arr[1000001];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr, arr + n);

	int l = 1;
	int r = arr[0];

	while (l <= r) {
		int mid = (l + r) / 2;
		ll sum = 0;

		for (int i = n - 1; i >= 0; i--) {
			if (arr[i] - mid > 0) sum += arr[i] - mid;
			else break;
		}


		if (sum < m) r = mid - 1;
		else l = mid + 1;
	}

	cout << r;


	return 0;
}