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



int n, x;
vector<int> v;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	v.push_back(-1);
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (v.back() < x) v.push_back(x);
		else {
			auto it = lower_bound(v.begin(), v.end(), x);
			*it = x;
		}
	}
	cout << v.size() - 1;

	return 0;
}