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

int n, m, sum;
int arr[10000];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);


	cin >> n;
	int mx = 0;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		mx = max(mx, arr[i]);
		sum += arr[i];
	}

	cin >> m;

	if (m >= sum) {
		cout << mx;
		return 0;
	}


	int l = 0;
	int r = 100001;

	while (l < r) {
		int mid = (l + r) / 2;
		int res = 0;

		for (int i = 0; i < n; i++) {
			if (mid >= arr[i]) res += arr[i];
			else res += mid;
		}

		if (res <= m) l = mid + 1;
		else r = mid - 1;
	}

	cout << l - 1;


	return 0;
}