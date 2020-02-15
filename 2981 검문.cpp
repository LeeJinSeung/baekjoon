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
typedef pair<ll, pii> pip;

int n, x, g;
vector<int> v;
vector<int> diff;
set<int> res;


int gcd(int a, int b) {
	if (b == 0)
		return a;
	else return gcd(b, a % b);
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n - 1; i++) {
		diff.push_back(v[i + 1] - v[i]);
	}

	sort(diff.begin(), diff.end());

	g = diff[0];

	for (int i = 0; i < diff.size(); i++) {
		g = gcd(g, diff[i]);
	}
	res.insert(g);
	for (int i = 2; i <= sqrt(g); i++) {
		if (g % i == 0) {
			res.insert(i);
			res.insert(g / i);
		}
	}
	for (auto a : res)
		cout << a << " ";

	return 0;
}