#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n;
int arr[51];
int res[7];

void dfs(int cur, int cnt) {
	if (cnt == 6) {
		for (int i = 1; i <= 6; i++) {
			cout << res[i] << " ";
		}
		cout << '\n';
		return;
	}

	if (cur >= n) return;
	res[cnt + 1] = arr[cur + 1];
	dfs(cur + 1, cnt + 1);
	dfs(cur + 1, cnt);
}

int main() {

	cin >> n;
	while (n != 0) {
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}

		dfs(0, 0);
		cout << '\n';

		cin >> n;
	}

	return 0;
}