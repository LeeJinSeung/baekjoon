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

int n, m, x;
int arr[500001];
vector<pii> v;


int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	v.push_back(pii(arr[0], 1));
	for (int i = 1; i < n; i++) {
		if (v.back().first == arr[i]) v.back().second++;
		else v.push_back(pii(arr[i], 1));
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x;
		int l = 0;
		int r = v.size() - 1;
		int res = 0;
		while (l <= r) {
			int mid = (l + r) / 2;

			if (v[mid].first == x) {
				res = v[mid].second;
				break;
			}
			else if (v[mid].first > x) r = mid - 1;
			else l = mid + 1;
		}

		cout << res << ' ';
	}




	return 0;
}