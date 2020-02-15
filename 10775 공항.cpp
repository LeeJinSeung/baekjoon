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

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int g, p, x, res, cnt;
int arr[100001];

int find(int n) {
	if (n == arr[n]) return n;
	return arr[n] = find(arr[n]);
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> g >> p;
	for (int i = 1; i <= g; i++) arr[i] = i;

	for (int i = 0; i < p; i++) {
		cin >> x;
		res = find(x);
		if (res == 0) break;
		cnt++;
		arr[res] = res - 1;

	}
	cout << cnt;




	return 0;
}