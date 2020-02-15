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

int n;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);


	while (true) {
		cin >> n;
		if (n == 0) break;
		stack<pii> st;
		ll res = 0;
		for (int i = 0; i <= n; i++) {
			int h;
			if (i < n)
				cin >> h;
			else
				h = -1;
			int left = i;

			while (!st.empty() && st.top().second > h) {
				res = max(res, ((ll)i - st.top().first) * st.top().second);
				left = st.top().first;
				st.pop();
			}
			st.push(pii(left, h));
		}
		cout << res << '\n';
	}




	return 0;
}