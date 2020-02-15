#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int H[100001];

int histogram(int s, int e) {
	if (s == e) return 0;
	if (s + 1 == e) return H[s];

	int mid = (s + e) / 2;
	int result = max(histogram(s, mid), histogram(mid, e));

	int w = 1;
	int h = H[mid];
	int l = mid;
	int r = mid;
	while (r - l + 1 < e - s) {
		int p, q;
		if (l > s) p = min(h, H[l - 1]);
		else p = -1;

		if (r < e - 1) q = min(h, H[r + 1]);
		else q = -1;

		if (p >= q) {
			h = p;
			l--;
		}
		else {
			h = q;
			r++;
		}
		result = max(result, ++w*h);
	}
	return result;
}

int main() {
	std::ios::sync_with_stdio(false);	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> H[i];
	}
	cout << histogram(0, n);

	return 0;
}